#include <linux/module.h> /* We're doing kernel work. Specifically, a module */
#include <asm-generic/errno.h> /* Standard errors */
#include <linux/tty.h>      /* For fg_console */
#include <linux/kd.h>       /* For KDSETLED */
#include <linux/vt_kern.h>
#include <linux/proc_fs.h> /* Necessary because we use proc fs */

/* Module information */
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Juguemos con los Leds del Teclado");
MODULE_AUTHOR("SO");

/* Local macros definitions */
#define ALL_LEDS_ON 0x7
#define ALL_LEDS_OFF 0
#define MAX_SIZE 5

/* Keyboard driver */
struct tty_driver* kbd_driver= NULL;
/* procfs entry struct */
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

/* Write callback for procfs entry */
static ssize_t procleds_write(struct file *filp, const char __user *buf, size_t len, loff_t *off) {

  /* Local buffer to keep data from user space */
  char str[MAX_SIZE];
  /* Leds are turned off at the beginning */
  unsigned int mask = ALL_LEDS_OFF;
  /* For index data buffer */
  int i;

  /* The application can write in this entry just once */
  if ((*off) > 0)
    return 0;

  /* is there enough space to save user space data? */
  if (len > MAX_SIZE - 1) {
    printk(KERN_INFO "PROCLEDS: Incorrect command\n");
    return -ENOSPC;
  }

  /* Transfer data from user to kernel space in a secure way */
  /* copy_to_user is an alternative to write_proc */
  if (copy_from_user(&str[0], buf, len))
    return -EFAULT;

  /* Final mark of an standard string */
  str[len] = '\0';

  for (i=0; i < len -1; i++) {

    printk(KERN_INFO "%c", str[i]);

    switch (str[i]) {
      case '1':
        /* Set Num Lock */
	      mask |= (1<<1);
        break;
      case '2':
        /* Set Caps Lock */
        mask |= (1<<2);
        break;
      case '3':
        /* Set Scroll Lock */
        mask |= 1;
        break;
      case '\n':
        /* A new line mark was detected. There are no more digits to read */
        break;
      case '\0':
        /* A null mark was detected. There are no more digits to read */
        break;
      default:
	      printk(KERN_INFO "PROCLEDS: Opcion enviada no valida\n");
    }
  }

  /* Set leds */
  set_leds(kbd_driver,mask);

  /* Update the file pointer */
  *off+=len;

  return len;
}

/* File operations for procfs entry */
static const struct file_operations proc_entry_fops = {
  .write = procleds_write,
};

/* Module init function */
static int __init procleds_init(void) {

  int ret = 0;

  /* get & set KDB driver */
  kbd_driver = get_kbd_driver_handler();

  /* Create procfs entry */
  proc_entry = proc_create( "leds", 0666, NULL, &proc_entry_fops);
  if (proc_entry == NULL) {
    ret = -ENOMEM;
    printk(KERN_INFO "PROCLEDS: Can't create /proc entry\n");
  } else {
      printk(KERN_INFO "PROCLEDS: Module loaded\n");
  }

  return ret;
}

/* Module cleanup function */
static void __exit procleds_exit(void) {
  /* Turn the leds off */
  set_leds(kbd_driver,ALL_LEDS_OFF);
  /* Removes procfs entry */
  remove_proc_entry("leds", NULL);
}

/* Set the module init funtion */
module_init(procleds_init);
/* Set the module exit funtion */
module_exit(procleds_exit);
