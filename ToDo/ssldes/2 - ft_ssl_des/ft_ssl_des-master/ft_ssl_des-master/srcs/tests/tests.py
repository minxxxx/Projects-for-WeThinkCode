#!/usr/bin/env python3
import subprocess
import sys
import tempfile
import shutil
import os
from termcolor import colored

from tests_functions import check_hmac_sha1, check_des_ecb, check_parse_error, check_des_cbc, check_des_cbc_against_real, check_base64_against_real
import tests_functions

def RUN_BASE64_TESTS():
	print ("BASE64")
	tests_functions.current_nfalse = 0;
	tests_functions.current_test_nbr = 0

	check_base64_against_real(b"pouet")
	check_base64_against_real(b"pouet", encrypt_with_mine=False)

	check_base64_against_real(b"")
	check_base64_against_real(b"", encrypt_with_mine=False)

	check_base64_against_real(b"oiweoifewhoifewhofeiohfweweoifhweoifhweoifhewoifhweoiieowfhweiofhioewoiefwfewhooiweoifewhoifewhofewhewfoifwhoiwehfoewihfewofhewofhewfhoewifhewoifhweoifioewhfoiewhfoowihfewoiohfweweoifhweoifhweoifhewoifhweoiieowfhweiofhioewoiefwfewho")
	check_base64_against_real(b"oiweoifewhoifewhofewhewfoifwhoiwehfoewihfewofhewofhewfhoewifhewoifhweoifioewhfoiewhfoiewhfoiewhfoiewhfiowehfoiewhfioewhfioewhfowehifewofhweoifhewoifhewoifhewiofhewifhewoifhweoiieowfhweiofhioewoiefwfewho", encrypt_with_mine=False)

	print("Number of false : ( {} / {} )".format(colored(tests_functions.current_nfalse, "red"), colored(tests_functions.current_test_nbr, "green")))

def RUN_HMAC_SHA1_TESTS():
	print ("HMAC_SHA1 : ")

	tests_functions.current_nfalse = 0;
	tests_functions.current_test_nbr = 0
	check_hmac_sha1(b"\x0b" * 20, b"Hi There", "b617318655057264e28bc0b6fb378c8ef146be00")
	check_hmac_sha1(b"Jefe", b"what do ya want for nothing?", "effcdf6ae5eb2fa2d27416d5f184df9c259a7c79")
	check_hmac_sha1(b"\xaa" * 20, b"\xdd" * 50, "125d7342b9ac11cd91a39af48aa17b4f63f175d3")
	check_hmac_sha1(b"\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19", b"\xcd" * 50, "4c9007f4026250c6bc8414f9bf50c86c2d7235da")
	check_hmac_sha1(b"\x0c" * 20, b"Test With Truncation", "4c1a03424b55e07fe7f27be1d58bb9324a9a5a04")
	check_hmac_sha1(b"\xaa" * 80, b"Test Using Larger Than Block-Size Key - Hash Key First", "aa4ae5e15272d00e95705637ce8a3b55ed402112")
	check_hmac_sha1(b"\xaa" * 80, b"Test Using Larger Than Block-Size Key and Larger Than One Block-Size Data", "e8e99d0f45237d786d6bbaa7965c7808bbff1a91")

	print("Number of false : ( {} / {} )".format(colored(tests_functions.current_nfalse, "red"), colored(tests_functions.current_test_nbr, "green")))


def RUN_DES_ECB_TESTS():
	print ("DES_ECB : ")
	tests_functions.current_nfalse = 0
	tests_functions.current_test_nbr = 0

	check_des_ecb(b"133457799BBCDFF1", b"jcamhi\n", b"\xf2\x9e\xc5\x74\xd3\xbe\x8e\xb6", False)
	check_des_ecb(b"133457799BBCDFF1", b"jcamhi\n", b"\xf2\x9e\xc5\x74\xd3\xbe\x8e\xb6", False, mine=False)
	check_des_ecb(b"133457799BBCDFF1", b"\xf2\x9e\xc5\x74\xd3\xbe\x8e\xb6",  b"jcamhi\n", True, mine=False)
	check_des_ecb(b"133457799BBCDFF1", b"salutcavajesuisbeauetforthahahahahaha", b"\x4d\x7f\x30\x1a\xfe\x18\x94\xe9\x61\xe2\x8d\xc3\xb0\x17\xd2\xe5\x9e\xb8\x8b\x77\xfe\x70\x3f\x58\x36\x9d\x49\x7c\xdb\xb0\x85\x0b\xf9\xc7\x64\x43\x3a\xfe\x0d\xc0", False)
	check_des_ecb(b"133457799BBCDFF1", b"\x4d\x7f\x30\x1a\xfe\x18\x94\xe9\x61\xe2\x8d\xc3\xb0\x17\xd2\xe5\x9e\xb8\x8b\x77\xfe\x70\x3f\x58\x36\x9d\x49\x7c\xdb\xb0\x85\x0b\xf9\xc7\x64\x43\x3a\xfe\x0d\xc0", b"salutcavajesuisbeauetforthahahahahaha", True)

	print("Number of false : ( {} / {} )".format(colored(tests_functions.current_nfalse, "red"), colored(tests_functions.current_test_nbr, "green")))

def RUN_DES_CBC_TESTS():
	print ("DES_CBC : ")
	tests_functions.current_nfalse = 0
	tests_functions.current_test_nbr = 0

	check_des_cbc(b"133457799BBCDFF1", b"0000000000000000", b"jcamhi\n", b"\xf2\x9e\xc5\x74\xd3\xbe\x8e\xb6", False)
	check_des_cbc(b"133457799BBCDFF1", b"0000000000000000", b"jcamhi\n", b"\xf2\x9e\xc5\x74\xd3\xbe\x8e\xb6", False, mine=False)
	check_des_cbc(b"133457799BBCDFF1", b"12345689AB000000", b"jcamhi\n", b"\x3c\x13\x1c\x13\xd7\x25\xe7\x42", False)
	check_des_cbc(b"133457799BBCDFF1", b"12345689AB000000", b"jcamhi\n", b"\x3c\x13\x1c\x13\xd7\x25\xe7\x42", False, mine=False)
	check_des_cbc(b"133457799BBCDFF1", b"12345689AB000000", b"Test Using Larger Than One Block-Size Data", b"", False, against_real_one=True)

	check_des_cbc_against_real(b"jcamhi", b"a", encrypt_with_mine=True)
	check_des_cbc_against_real(b"fwubefoboewbfeowbiofewfioewbfoeiwboefwbifewoifewiobfewoibfewoibefwbfeiw", b"afewihfiewofhewoifheoiw", encrypt_with_mine=True)
	check_des_cbc_against_real(b"\x01\x02\x01\x02\x01\x02\x01\x02\x01\x02\x01\x02\x01\x02\x03\x04\x03\x04\x03\x04\x00\x01", b"afewihfiewofhewoifheoiw", encrypt_with_mine=True)

	check_des_cbc_against_real(b"jcamhi", b"a", encrypt_with_mine=False)
	check_des_cbc_against_real(b"fwubefoboewbfeowbiofewfioewbfoeiwboefwbifewoifewiobfewoibfewoibefwbfeiw", b"afewihfiewofhewoifheoiw", encrypt_with_mine=False)
	check_des_cbc_against_real(b"\x01\x02\x01\x02\x01\x02\x01\x02\x01\x02\x01\x02\x01\x02\x03\x04\x03\x04\x03\x04\x00\x01", b"afewihfiewofhewoifheoiw", encrypt_with_mine=False)

	print("Number of false : ( {} / {} )".format(colored(tests_functions.current_nfalse, "red"), colored(tests_functions.current_test_nbr, "green")))


def RUN_PARSING_TESTS():
	print ("PARSING : ")
	tests_functions.current_nfalse = 0
	tests_functions.current_test_nbr = 0

	temp_dir = tempfile.mkdtemp(prefix="testing_", dir=".");
	os.chdir(temp_dir)

	check_parse_error([b'dex'], b'Unknown algorithm: dex\n\nStandard commands\n\nMessage Digest commands\nmd5\tsha1\tsha256\tsha512\n\nCipher commands\nbase64\tdes\tdes-cbc\tdes-ecb\n\n')
	check_parse_error([b'des', b'-e', b'-ix'], b'Error while trying to open file for reading.\n')

	check_parse_error([b'des', b'-e', b'-i.', '-pa'], b"Can't stat input file, or the input file is a folder.\n")
	check_parse_error([b'des', b'-d', b'-i', b'../Makefile', '-kz'], b'Error : Problem while parsing the key\n')
	check_parse_error([b'des', b'-d', b'-i', b'../Makefile', '-vaz'], b'Error : Problem while parsing the iv\n')
	check_parse_error([b'des', b'-d', b'-i', b'../Makefile', '-va', '-kz'], b'Error : Problem while parsing the key\n')

	check_parse_error([b'hmac-sha1', b'-k', b'abc', b'-i', 'Makefile'], b"Error : Couldn't open input file or parse error\n")
	check_parse_error([b'hmac-sha1', b'-i', '../Makefile'], b'Key needed\n')

	os.chdir("..")
	shutil.rmtree(temp_dir)
	print("Number of false : ( {} / {} )".format(colored(tests_functions.current_nfalse, "red"), colored(tests_functions.current_test_nbr, "green")))

def main():

	total_nfalse = 0
	total_test_nbr = 0

	RUN_PARSING_TESTS()
	total_nfalse += tests_functions.current_nfalse
	total_test_nbr += tests_functions.current_test_nbr
	RUN_HMAC_SHA1_TESTS()
	total_nfalse += tests_functions.current_nfalse
	total_test_nbr += tests_functions.current_test_nbr
	RUN_DES_ECB_TESTS()
	total_nfalse += tests_functions.current_nfalse
	total_test_nbr += tests_functions.current_test_nbr
	RUN_DES_CBC_TESTS()
	total_nfalse += tests_functions.current_nfalse
	total_test_nbr += tests_functions.current_test_nbr
	RUN_BASE64_TESTS()
	total_nfalse += tests_functions.current_nfalse
	total_test_nbr += tests_functions.current_test_nbr

	print("------------------------")
	print("Total number of false : ( {} / {} )".format(colored(total_nfalse, "red"), colored(total_test_nbr, "green")))
	return total_nfalse

if __name__ == '__main__':
	sys.exit(main())
