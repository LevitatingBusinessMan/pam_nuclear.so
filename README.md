# pam_nuclear.so

This is a Linux-PAM module that will nuke your root drive if a pre-configured password is used.

## Building and Installing
```
make
sudo make install
```

The `install` target will install the module in `/usr/lib/security/`.

## Usage
Configure the module for any service. For instance for `login` you could use:
```
#/etc/pam.d/login

auth    requisite   pam_nologin.so
auth    optional    pam_nuclear.so  myveryrealpassword
auth    required    pam_unix.so

```
The nuclear password should be set in the aguments for the module.

# Disclaimer
This project actually contains code that can and will harm your system.
I am in no way responsible for your data loss.
