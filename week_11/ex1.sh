sudo fallocate -l 50M lofs.img
sudo losetup -f lofs.img
losetup -a
sudo mkfs.ext4 /dev/loop0
sudo mount /dev/loop0 lofsdick
