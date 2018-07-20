dram=$(cat elf.log | grep '0x400' | grep -v '0x4008' | grep -v '0x400c' | awk '{print "-j", $1 }')
iram=$(cat elf.log | grep '0x400' | grep -v '0x4008' | grep -v '0x400c' | awk '{print "-R", $1 }')
dram_start=$(cat elf.log | grep '0x4000' | sed '2, $d' | awk '{print $3}')
iram_start=$(cat elf.log | grep '0x4008' | sed '2, $d' | awk '{print $3}')
sync
#echo ===== Generate RST3111 binary image files for IRAM and DRAM =====
rm -vf os.checked.*
echo xt-objcopy --xtensa-core=fusion201511_RF3 $dram -O binary $1 os.checked.dram.$dram_start
echo xt-objcopy --xtensa-core=fusion201511_RF3 $iram -O binary $1 os.checked.iram.$iram_start
xt-objcopy --xtensa-core=fusion201511_RF3 $dram -O binary $1 os.checked.dram.$dram_start
xt-objcopy --xtensa-core=fusion201511_RF3 $iram -O binary $1 os.checked.iram.$iram_start
sync
dram_image_size=$(stat -c%s "os.checked.dram.$dram_start")
iram_image_size=$(stat -c%s "os.checked.iram.$iram_start")

# pad zero data to satisfy 256 bytes as one data chunk
bash images_pad.sh

((dram_max = ((224*1024)-0x400)))
if ((dram_image_size > dram_max)); then
  echo "===== ERROR: os.checked.dram.$dram_start generated failure, size $(stat -c%s "os.checked.dram.$dram_start") > $dram_max ====="
  rm -f elf.log
  rm -vf os.checked.dram.$dram_start
else
  rm -f elf.log
  printf "  OS DRAM SIZE:       %6d bytes\n" $(stat -c%s "os.checked.dram.$dram_start")
fi

((iram_max = (336*1024)))
if ((iram_image_size > iram_max)); then
  echo "===== ERROR: os.checked.iram.$iram_start generated failure, size $(stat -c%s "os.checked.iram.$iram_start") > $iram_max ====="
  rm -f elf.log
  rm -vf os.checked.iram.$iram_start
else
  rm -f elf.log
  printf "  OS IRAM SIZE:       %6d bytes\n" $(stat -c%s "os.checked.iram.$iram_start")
fi
