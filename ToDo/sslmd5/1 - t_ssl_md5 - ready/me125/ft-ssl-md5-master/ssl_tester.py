import random
import sys
import subprocess
import string
import os

POSS_CHARS = string.ascii_lowercase + string.ascii_uppercase + string.digits
VISIBLE = False
HEX_CHARS = "0123456789abcdef"
LEFT_BOUND = 17
HIGH_BOUND = 500
STEP = 17
DES3 = True

def exec_test(ssl, cipher, text, args, echo):
    if not echo:
        command = '{} {} {}'.format(ssl, cipher, args)
    else:
        command = 'echo "{}" | {} {} {}'.format(text, ssl, cipher, args)
    if VISIBLE:
        print command
    out = subprocess.check_output(command, shell=True)
    return out

def generate_key():
    key = ""
    for i in range(random.randint(1, 48)):
        key += random.choice(HEX_CHARS)
    return key
def generate_random_text(size):
    text = ""
    for _ in range(size):
        text += random.choice(POSS_CHARS)
    return text

def base64_test(text):
    ft_ssl_enc = exec_test("./ft_ssl", "base64", text, "-e", True)
    openssl_enc = exec_test("openssl", "base64", text, "-e", True)
    ft_ssl_dec = exec_test("./ft_ssl", "base64", ft_ssl_enc, "-d", True)
    openssl_dec = exec_test("openssl", "base64", openssl_enc, "-d", True)
    return [[ft_ssl_enc, ft_ssl_dec], [openssl_enc, openssl_dec]]
def base64_tests():
    err = False
    for i in range(LEFT_BOUND, HIGH_BOUND, STEP):
        text = generate_random_text(i)
        res = base64_test(text)
        if res[0][0] != res[1][0] or res[0][1] != res[1][1]:
            err = True
            print ("Error occured: ")
            print ("       text: {}".format(text))
            print (" ft_ssl_enc: {}".format(res[0][0])),
            print ("openssl_enc: {}".format(res[1][0])),
            print (" ft_ssl_dec: {}".format(res[0][1])),
            print ("openssl_dec: {}".format(res[1][1])),
            exit(1)
    if not err:
        print "All OK!"

def des_test(des_type, text, flags, key):
    open("text", "w").write(text)
    ft_ssl_enc = exec_test("./ft_ssl", des_type[0], "", flags + " -k " + key + " -i text", False)
    openssl_enc = exec_test("openssl", des_type[1], "", flags + " -K " + key + " -in text", False)
    open("encoded", "w").write(openssl_enc)
    ft_ssl_dec = exec_test("./ft_ssl", des_type[0], "", "-d " + flags + " -k " + key + " -i encoded", False)
    openssl_dec = exec_test("openssl", des_type[1], "", "-d " + flags + " -K " + key + " -in encoded", False)
    if VISIBLE:
        print (ft_ssl_enc, openssl_enc)
        print (ft_ssl_dec, openssl_dec)
    return [[ft_ssl_enc, ft_ssl_dec], [openssl_enc, openssl_dec]]

def des_tests(flags, des_type):
    err = False
    for i in range(LEFT_BOUND, HIGH_BOUND, STEP):
        text = generate_random_text(i)
        key = generate_key()
        res = des_test(des_type, text, flags, key)
        if res[0][0] != res[1][0] or res[0][1] != res[1][1]:
            err = True
            print ("Error occured: ")
        if err or VISIBLE:
            print ("       text: {}".format(text))
            print (" ft_ssl_enc: {}\n".format(res[0][0])),
            print ("openssl_enc: {}\n".format(res[1][0])),
            print (" ft_ssl_dec: {}\n".format(res[0][1])),
            print ("openssl_dec: {}\n".format(res[1][1])),
        if err:
            exit(1)
    if not err:
            print "All OK!"

def descbc_test(des_type, text, flags, key, iv):
    open("text", "w").write(text)
    ft_ssl_enc = exec_test("./ft_ssl", des_type[0], "", flags + " -k " + key + ' -v ' + iv[:16] + " -i text", False)
    openssl_enc = exec_test("openssl", des_type[1], "", flags + " -K " + key + ' -iv ' + iv[:16] + " -in text", False)
    open("encoded", "w").write(openssl_enc)
    ft_ssl_dec = exec_test("./ft_ssl", des_type[0], "", "-d " + flags + " -k " + key + ' -v ' + iv[:16] + " -i encoded", False)
    openssl_dec = exec_test("openssl", des_type[1], "", "-d " + flags + " -K " + key + ' -iv ' + iv[:16] + " -in encoded", False)
    if VISIBLE:
        print (ft_ssl_enc, openssl_enc)
        print (ft_ssl_dec, openssl_dec)
    return [[ft_ssl_enc, ft_ssl_dec], [openssl_enc, openssl_dec]]

def descbc_tests(des_type, flags):
    err = False
    for i in range(LEFT_BOUND, HIGH_BOUND, STEP):
        text = generate_random_text(i)
        key = generate_key()
        iv = generate_key()
        res = descbc_test(des_type, text, flags, key, iv)
        if res[0][0] != res[1][0] or res[0][1] != res[1][1]:
            err = True
            print ("Error occured: ")
        if err or VISIBLE:
            print ("       text: {}".format(text))
            print (" ft_ssl_enc: {}\n".format(res[0][0])),
            print ("openssl_enc: {}\n".format(res[1][0])),
            print (" ft_ssl_dec: {}\n".format(res[0][1])),
            print ("openssl_dec: {}\n".format(res[1][1])),
        if err:
            exit(1)
    if not err:
        print "All OK!"


def main():
    print "Base64 tests..."
    base64_tests()
    print "Des-ecb tests..."
    des_tests("", ["des-ecb", "des-ecb"])
    print "Des-ecb with -a tests..."
    des_tests(" -a ", ["des-ecb", "des-ecb"])
    print "Des-cbc tests..."
    descbc_tests(["des-cbc", "des-cbc"], "")
    print "Des-cbc with -a tests..."
    descbc_tests(["des-cbc", "des-cbc"], " -a ")
    if DES3:
        print "Des3-ecb tests"
        des_tests("", ["des3-ecb", "des-ede3"])
        print "Des3-ecb with -a tests"
        des_tests(" -a ", ["des3-ecb", "des-ede3"])
        print "Des3-cbc tests..."
        descbc_tests(["des3-cbc", "des3"], "")
        print "Des3-cbc with -a tests..."
        descbc_tests(["des3-cbc", "des3"], " -a ")

main()
