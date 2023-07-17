import shutil
Import("env")


def copy_firmware_action(source, target, env):
    print("Copy firmware")
    shutil.copyfile(target[0].get_abspath(),f"lnbits/bliksembier/static/firmware/{target[0].name}")

def copy_partitions_action(source, target, env):
    print("Copy partitions")
    shutil.copyfile(target[0].get_abspath(),f"lnbits/bliksembier/static/firmware/{target[0].name}")

def copy_bootloader_action(source, target, env):
    print("Copy bootloader")
    shutil.copyfile(target[0].get_abspath(),f"lnbits/bliksembier/static/firmware/{target[0].name}")

env.AddPostAction("$BUILD_DIR/${PROGNAME}.bin", copy_firmware_action)
env.AddPostAction("$BUILD_DIR/partitions.bin", copy_partitions_action)
env.AddPostAction("$BUILD_DIR/bootloader.bin", copy_bootloader_action)

