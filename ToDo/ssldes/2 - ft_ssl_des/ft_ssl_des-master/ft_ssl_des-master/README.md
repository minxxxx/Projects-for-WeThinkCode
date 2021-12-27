# ft_ssl_des

Implementation of multiple components of the openssl binary.
This includes :

#### Hash functions :
- md5
- sha1
- sha256

#### Message Authentication Codes (MAC) :
- hmac-sha1

#### Key Derivation Functions
- pbkdf2-hmac-sha1
- EVP_BytesToKey (default openssl kdf)

#### Encoding Functions :
- base64

#### Encryption Functions :
- des-cbc
- des-ecb

All those functions are written in C only, by myself, according to the relevant RFCs and FIPS publications.

This repo also includes unit tests, which can be run by running `make test`, or `./run_tests.py`.
