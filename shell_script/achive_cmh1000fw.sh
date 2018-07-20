# ! /bin/bash
GIT_TAG=$1

achive_fw_image()
{
  GIT_TAG_NUMBER=$(git tag -l --sort=-taggerdate | grep $GIT_TAG | head -1)
  if [ -z "$GIT_TAG_NUMBER" ]; then
    echo "GIT TAG: $1 is not existing"
  else
    rm -f sensorhub_fw_$GIT_TAG_NUMBER.zip
    echo -e "Create sensorhub_fw_$GIT_TAG_NUMBER.zip\n"
    find ./chre/firmware -type f -name "os.checked.*" -print | zip -qj sensorhub_fw_$GIT_TAG_NUMBER.zip -@
  fi
}

if [ -z "$GIT_TAG" ]; then
  echo "ERROR: \$1 is empty, you have to fill GIT tag keyword is similar \"04B\", \"08D\"...etc"
else
  achive_fw_image
fi
