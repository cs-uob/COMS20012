# Secure boot

## Introduction

In this lab we are going to simulate how secure boot works. We will have a simple image that can be executed.
This image will be signed using a private key. Later the image will be "booted" by loading the image, validating it and then running the image.

### Setting up Vagrant

The rest of labs in this course are designed to run in *virtual machines* on the lab machines setup via Vagrant. Expect to spend the first 10 minutes
of any lab redownloading the VM images.

1. On your host machine, open a terminal in your home directory (or whatever directory you are asigned which has good memory). Make a directory `mkdir CS_vagrant`
2. `cd CS_vagrant` and then make another directory `mkdir seclabs`
3. `cd seclabs`
4. `vagrant init hashicorp/bionic64`.
5. `vagrant up`. First time, this will download Ubuntu 18.04-64. It will take a while. Once done, we are ready to launch this VM.
6. Lets ssh our new VM. `vagrant ssh`
7. You are in your new VM. This VM shares a folder with your host machine, which is the same folder from where you lanched your VM, i.e. `seclabs`.
   This folder is mapped to `/vagrant` in your VM. if you do `cd /vagrant`, you can see the content of your host folder.
   We will use this folder for all our work (i.e. you can copy your files in seclabs folder and access them from /vagrant folder from VM).
8. This VM is running a fresh Ubuntu. So, we need to get few things installed in this. Lets do it. Run these commands.
9. `sudo apt update`
10. `sudo apt install build-essential -y` This will install gcc.
11. `sudo apt install openssl libssl-dev -y` This will install openssl command line and libraries ssl crypto.
12. Now you have all the tools that will be required. To test, run these commends and check if they run properly-- `gcc --version`, `openssl --version`
13. When done with your lab, you can `logout` and then in your host machine, you can close the VM-- `vagrant halt`

### Singing and validating the image

The image is signed using the utility `image_sign`, this utility takes the private key, the public key and the image, then generates the signed image using the following steps:

1. The signature of the image is generated using the private key.
2. The signed image is then created by writing out the header, the public key, signature and the image.
3. The source for the utility is in the file `image_sign.c`

The `secure_boot` utility will simulate the boot process in a device. This utility will read the singed image, validate the image and if successful run the image.

1. The image validation uses the public key. This public key is stored in the singed image file.
2. This public key must also be validated before it can be used to validate the image. this is done in the function `verify_public_key()`
3. The public key is hashed to generate the fingerprint
   1. The `generated fingerprint` is  compared to the `device fingerprint`.
      In this case the `device fingerprint` is compiled in to the `secure_boot` utility.
   2. If the fingerprints are the same then the public key can be used to validate the image
4. The image is validated in the function `verify_image()`
   1. The hash of the image is calculated
   2. This hash is the compared with the encrypted hash in the signature
   3. If they are the same the image is valid
5. The source for the utility is in the file `secure_boot.c`

Only images that are signed with the corresponding private key can be validated by the `secure_boot` utility and the run.

### The image

The image is a simple shell script that we can run.
But before running the image we need to validate that the image is signed using the private key.
Below is the test script that we will be using:

```bash
#!/bin/bash
echo "Hello, World!"
```

## Signing the image

### Generating the private and public keys

Before signing any images, we need to generate a private and public key pair:

1. `openssl genrsa -out privatekey.pem 2048` This generates the new private key
2. `openssl rsa -in privatekey.pem -outform PEM -pubout -out publickey.pem` The generates the public key from the private key

### Provision the public key fingerprint

The public key needs to be provisioned in to the `secure_boot` utility by adding the value in to the source `secure_boot.c`.
The fingerprint is in the varable `s_public_key_fingerprint` below:

```c
/**
 * The fingerprint of the public key used to validate the key
 */
static  unsigned char s_public_key_fingerprint[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,};
```

1. This value needs to be replaced with the fingerprint of the public key we have already generated.
2. `openssl dgst -sha256 -binary -out publickey.sha256.bin publickey.pem` This will create a sha256 hash of the public key
3. `xxd -p publickey.sha256.bin | tr -d '\n' | sed 's/../0x&\,/g; s/,$//'` To view the file as the file in the format 0x??,
4. Update the `s_public_key_fingerprint` in the source code `secure_boot.c`.
5. We have now provisioned the public key fingerprint

### Example of signing and verifying the image

The `sign_image` utility generates the signature, then `secure_boot` will use the signature to validate the image.
As an example, we can use the openssl command line to create a signature and then use the signature to validate the image.

1. `openssl dgst -sha256 -sign privatekey.pem -out image.signature image.sh` This generates a image signiture `image.signature`.
2. `xxd image.signature` To view the the signiture
3. `openssl dgst -sha256 -verify publickey.pem -signature image.signature image.sh` This will validate the

### Signing the image using `sign_image` utility

1. We need to build the `sign_image` untility.
2. `gcc -o sign_image sign_image.c -lssl -lcrypto` This will build the `sign_image` utility from source.
3. Once built we can then use the utility sign the image
4. `./sign_image image.sh publickey.pem privatekey.pem` This will generate the image.sh.singed file with the public key, signature and image

## Validating the secure boot image

Validating the image is done in two steps:

1. Validate the public key with the provisioned fingerprint
2. Validate the image with the signature and the public key

## Validating the public key

1. `gcc -o secure_boot secure_boot.c -lssl -lcrypto` This will bild the `secure_boot` utility.
2. `./secure_boot image.sh.signed` This will validate the image and if it is valid then run the image.
3. Runing `secure_boot` utility will fail as the function that validates the public is not implemented

```c
/**
 * Validate the public key with the built-in interface
 *
 * @param[in] public_key_buf
 *
 * @return 1 - the public key is valid
 *         0 - the key is not valid
 */
int verify_public_key(const str_buf_t *public_key_buf)
{
    return SB_OK;
}
```

1. The ssl function `EVP_Digest((void *)key, key_len, hash, NULL, EVP_sha256(), NULL)` will generate a `sha256` of the key.
2. If the generated hash is the same as the `s_public_key_fingerprint` then the function can return 1.
3. Implement the `verify_public_key()` function to validate the public key.
4. Once the public key is validated corrected the image will still be run and `secure_boot` should return the error `Failed signature validation`.

## Validating the Image

```c
/**
 * verify the boot image
 *
 * @param[in] image the image buffer
 * @param[in] signature the signature buffer
 * @param[in] public_key the public key to validate the image
 *
 * @return 0 - the Image is not valid
 *         1 - the Image is valid
 *         -1 - an error
 */
int verify_image(const str_buf_t image, const str_buf_t signature, EVP_PKEY *public_key)
{
    return SB_OK;
}
```

1. Open ssl can be used to validate the image with the signature and public_key.
2. The ssl function `EVP_DigestVerifyInit(ctx, NULL, EVP_sha256(), NULL, public_key)` will set up verification context to use sha256 hash.
3. The function `EVP_DigestVerifyUpdate(ctx, image, image_len)` hashes the image.
4. The `EVP_DigestVerifyFinal(ctx, signaturer, signature_._len)` verifies the data in context against the signature
5. Implement the `verify_image()` function to validate the image, if the image is valid then return 1.
6. `secure_boot` should now run the image

## Extentions

### Using elliptic curve

1. Generate the elliptic curve public and private
2. Provition the public key

### Additional provitioned keys

1. Generate 3 additional private and public keys.
2. Update the code to allow the image to be validated using all of the provitioned keys
