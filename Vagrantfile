# -*- mode: ruby -*-
# vi: set ft=ruby :

# Vagrantfile for a base machine with a working setup of Latex on an ubuntu/trusty64 box
Vagrant.configure(2) do |config|
  config.vm.box = "ubuntu/trusty64"
  config.vm.network "private_network", ip: "10.100.10.10"
  config.vm.provider "virtualbox" do |vb|
    vb.name = 'latex'
    vb.memory = "1024"
  end

  config.vm.synced_folder '.', '/home/vagrant/contenidos'

  config.vm.provision "shell", inline: <<-SHELL
    sudo apt-get update
    sudo apt-get install -y git make texlive texlive-lang-spanish texlive-latex-recommended texlive-latex-extra texlive-fonts-recommended build-essential vim
  SHELL
end
