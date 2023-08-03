import shutil
import json
import re
Import("env")


import configparser
project_config = configparser.ConfigParser()
project_config.read("platformio.ini")
firmware_version = project_config.get("common", "firmware_version")


def copy_firmware_action(source, target, env):
    print("Copy firmware")
    shutil.copyfile(target[0].get_abspath(),f"lnbits/bliksembier/static/firmware/{env['PIOENV']}/{target[0].name}")

    # update manifest
    with open(f"lnbits/bliksembier/static/firmware/{env['PIOENV']}/manifest.json","r") as file:
        data = json.load(file)
    data['version'] = firmware_version
    with open(f"lnbits/bliksembier/static/firmware/{env['PIOENV']}/manifest.json","w") as file:
        json.dump(data,file,indent=4)

    # update version in index.html
    with open("lnbits/bliksembier/templates/bliksembier/index.html","r") as file:
        content = file.read()

    content = re.sub("version\: \'.*\',",f"version: \'{firmware_version}\',",content)

    with open("lnbits/bliksembier/templates/bliksembier/index.html","w") as file:
        file.write(content)
        
def copy_partitions_action(source, target, env):
    print("Copy partitions")
    shutil.copyfile(target[0].get_abspath(),f"lnbits/bliksembier/static/firmware/{env['PIOENV']}/{target[0].name}")

def copy_bootloader_action(source, target, env):
    print("Copy bootloader")
    shutil.copyfile(target[0].get_abspath(),f"lnbits/bliksembier/static/firmware/{env['PIOENV']}/{target[0].name}")

env.AddPostAction("$BUILD_DIR/${PROGNAME}.bin", copy_firmware_action)
env.AddPostAction("$BUILD_DIR/partitions.bin", copy_partitions_action)
env.AddPostAction("$BUILD_DIR/bootloader.bin", copy_bootloader_action)

