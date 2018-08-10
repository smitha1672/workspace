# ! /bin/bash
VER_NUM=$(echo "v15.$(cat chre/firmware/misc/variant/$1/Makefile | grep VARIANT | sed 's/FLAGS += -DVARIANT_VER=0x//')")
VARIANT_MK_PATH="chre/firmware/misc/variant/$1/Makefile"

achive_fw_image()
{
  rm -v sensorhub_fw_"${VER_NUM}".zip
  echo -e "Create sensorhub_fw_"${VER_NUM}".zip\n"
  find ./chre/firmware -type f -name "os.checked.*" -print | zip -qj sensorhub_fw_"${VER_NUM}".zip -@
}

if [ -f $VARIANT_MK_PATH ]; then
  echo "Project name is: $1"
  achive_fw_image
else
  echo "Error! Yours project name is empty: $1"
  echo "You should fill that it like as \$ source achive_cmh1000fw.sh 07_w906_zwcm0118"
  echo "Project name is as below:"
  find . -path "*/misc/variant/*" -type d -print | sed 's/.\/chre\/firmware\/misc\/variant\///'
fi
