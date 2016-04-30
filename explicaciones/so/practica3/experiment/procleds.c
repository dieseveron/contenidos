#include <linux/module.h>
#include <asm-generic/errno.h>
#include <linux/init.h>
#include <linux/tty.h>      /* For fg_console */
#include <linux/kd.h>       /* For KDSETLED */
#include <linux/vt_kern.h>
#include <linux/proc_fs.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Juguemos con los Leds del Teclado");
MODULE_AUTHOR("SO");

#define ALL_LEDS_ON 0x7
#define ALL_LEDS_OFF 0
#define MAX_SIZE 5

struct tty_driver* kbd_driver= NULL;
static struct proc_dir_entry *proc_entry;

/* Get driver handler */
struct tty_driver* get_kbd_driver_handler(void) {
   printk(KERN_INFO "modleds: loading\n");
   printk(KERN_INFO "modleds: fgconsole is %x\n", fg_console);
   return vc_cons[fg_console].d->port.tty->driver;
}

/* Set led state to that specified by mask */
static inline int set_leds(struct tty_driver* handler, unsigned int mask) {
  return (handler->ops->ioctl) (vc_cons[fg_console].d->port.tty, KDSETLED,mask);
}

static ssize_t procleds_write(struct file *filp, const char __user *buf, size_t len, loff_t *off) {

  char str[MAX_SIZE];
  unsigned int mask = ALL_LEDS_OFF;
  int i;

  if ((*off) > 0) /* The application can write in this entry just once !! */
    return 0;

  if (len > MAX_SIZE - 1) {
    printk(KERN_INFO "PROCLEDS: Incorrect command\n");
    return -ENOSPC;
  }

  /* Transfer data from user to kernel space */
  if (copy_from_user( &str[0], buf, len ))
    return -EFAULT;

  str[len] = '\0';

  for (i=0; i < len -1; i++) {
    printk(KERN_INFO "%c", str[i]);

    switch (str[i]) {
      case '1':
	mask |= (1<<1);
        break;
      case '2':
        mask |= (1<<2);
        break;
      case '3':
        mask |= 1;
        break;
      case '\n':
        break;
      case '\0':
        break;
      default:
	printk(KERN_INFO "PROCLEDS: Opcion enviada no valida\n");
    }
  }

  set_leds(kbd_driver,mask);

  *off+=len;            /* Update the file pointer */
  return len;
}


static const struct file_operations proc_entry_fops = {
  .write = procleds_write,
};

static int __init procleds_init(void) {

  int ret = 0;
  kbd_driver = get_kbd_driver_handler();

  proc_entry = proc_create( "leds", 0666, NULL, &proc_entry_fops);
  if (proc_entry == NULL) {
    ret = -ENOMEM;
    printk(KERN_INFO "PROCLEDS: Can't create /proc entry\n");
  } else {
      printk(KERN_INFO "PROCLEDS: Module loaded\n");
  }
  return ret;
}

static void __exit procleds_exit(void) {
  set_leds(kbd_driver,ALL_LEDS_OFF);
  remove_proc_entry("leds", NULL);
}

module_init(procleds_init);
module_exit(procleds_exit);
