#! /bin/sh
DRAM_FILE_NAME=os.checked.dram.0x40000400
IRAM_FILE_NAME=os.checked.iram.0x40080000

DRAM_FILE_SIZE=$(stat -c%s "$DRAM_FILE_NAME")
IRAM_FILE_SIZE=$(stat -c%s "$IRAM_FILE_NAME")

dram_chunk=$(($DRAM_FILE_SIZE / 256))
dram_unchunk=$(($DRAM_FILE_SIZE % 256))
iram_chunk=$(($IRAM_FILE_SIZE / 256))
iram_unchunk=$(($IRAM_FILE_SIZE % 256))

if [ $dram_unchunk -ne 0 ]; then
  dram_chunk=$(($dram_chunk + 1))
  size=$(($dram_chunk * 256))
  dram_pad_size=$(($size-$DRAM_FILE_SIZE))
  dd if=/dev/zero bs=1 count=$dram_pad_size >> $DRAM_FILE_NAME
  echo "Pad $dram_pad_size ZERO bytes to $DRAM_FILE_NAME"
fi

if [ $iram_unchunk -ne 0 ]; then
  iram_chunk=$(($iram_chunk + 1))
  size=$(($iram_chunk * 256))
  iram_pad_size=$(($size-$IRAM_FILE_SIZE))
  dd if=/dev/zero bs=1 count=$iram_pad_size >> $IRAM_FILE_NAME
  echo "Pad $iram_pad_size ZERO bytes to $IRAM_FILE_NAME"
fi
