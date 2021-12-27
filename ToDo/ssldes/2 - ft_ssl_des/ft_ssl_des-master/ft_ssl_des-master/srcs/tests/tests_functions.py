#!/usr/bin/env python3
import subprocess
import sys
import tempfile
import shutil
import os
from termcolor import colored
PROGRAM_NAME = os.getcwd() + "/ft_ssl"

current_nfalse = 0
current_test_nbr = 0

def check_hmac_sha1(key, data, expected_output):
	global current_nfalse
	global current_test_nbr

	expected_output += "\n"
	current_test_nbr += 1
	result = subprocess.run([PROGRAM_NAME, "hmac-sha1", b"-k" + key], stdout=subprocess.PIPE, stderr=subprocess.PIPE, input=data)
	out = result.stdout.decode("ascii")
	if result.stderr != b'':
		print (colored("Error", 'red'), " : Stderr not empty (", result.stderr, ") [", current_test_nbr, "]")
	elif out != expected_output:
		print (colored("Error", 'red'), " : [", expected_output, "] != [", out, "] [", current_test_nbr, "]")
	else:
		print (colored("OK", 'green'), "[", current_test_nbr, "]")
		return (True)
	current_nfalse += 1
	return (False)

def check_des_ecb(key, data, expected_output, decrypt, mine = True):
	global current_nfalse
	global current_test_nbr

	if (decrypt == True):
		mode = "-d"
	else:
		mode = "-e"

	current_test_nbr += 1

	if (mine == True):
		result = subprocess.run([PROGRAM_NAME, "des-ecb", mode, b"-k" + key], stdout=subprocess.PIPE, stderr=subprocess.PIPE, input=data)
	else:
		result = subprocess.run(["openssl", "des-ecb", mode, b"-K", key], stdout=subprocess.PIPE, stderr=subprocess.PIPE, input=data)

	if result.stderr != b'':
		print (colored("Error", 'red'), " : Stderr not empty (", result.stderr, ") [", current_test_nbr, "]")
	elif result.stdout != expected_output:
		print (colored("Error", 'red'), " : [", expected_output, "] != [", result.stdout, "] [", current_test_nbr, "]")
	else:
		print (colored("OK", 'green'), "[", current_test_nbr, "]")
		return (True)
	current_nfalse += 1
	return (False)

def	check_parse_error(command, expected_output, error_on_empty_stdout=True):
	global current_nfalse
	global current_test_nbr

	current_test_nbr += 1

	command = [PROGRAM_NAME] + command

	result = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	if (error_on_empty_stdout and result.stdout != b''):
		print (colored("Error", 'red'), " : Stdout not empty (", result.stdout, ") [", current_test_nbr, "]")
	elif (result.stderr != expected_output):
		print (colored("Error", 'red'), " : [", expected_output, "] != [", result.stderr, "] [", current_test_nbr, "]")
	else:
		print (colored("OK", 'green'), "[", current_test_nbr, "]")
		return (True)
	current_nfalse += 1
	return (False)

def check_des_cbc(key, iv, data, expected_output, decrypt, mine = True, against_real_one=False):
	global current_nfalse
	global current_test_nbr

	if (decrypt == True):
		mode = "-d"
	else:
		mode = "-e"

	current_test_nbr += 1

	if (against_real_one == False):
		if (mine == True):
			result = subprocess.run([PROGRAM_NAME, "des-cbc", mode, b"-k" + key, "-v", iv], stdout=subprocess.PIPE, stderr=subprocess.PIPE, input=data)
		else:
			result = subprocess.run(["openssl", "des-cbc", mode, b"-K", key, "-iv", iv], stdout=subprocess.PIPE, stderr=subprocess.PIPE, input=data)
	else:
		result = subprocess.run([PROGRAM_NAME, "des-cbc", mode, b"-k" + key, "-v", iv], stdout=subprocess.PIPE, stderr=subprocess.PIPE, input=data)
		other = subprocess.run(["openssl", "des-cbc", mode, b"-K", key, "-iv", iv], stdout=subprocess.PIPE, stderr=subprocess.PIPE, input=data)
		expected_output = other.stdout

	if result.stderr != b'':
		print (colored("Error", 'red'), " : Stderr not empty (", result.stderr, ") [", current_test_nbr, "]")
	elif result.stdout != expected_output:
		print (colored("Error", 'red'), " : [", expected_output, "] != [", result.stdout, "] [", current_test_nbr, "]")
	else:
		print (colored("OK", 'green'), "[", current_test_nbr, "]")
		return (True)
	current_nfalse += 1
	return (False)

def check_des_cbc_against_real(data, password, encrypt_with_mine=True):
	global current_nfalse
	global current_test_nbr

	current_test_nbr += 1
	if (encrypt_with_mine == True):
		encrypted_res = subprocess.run([PROGRAM_NAME, "des-cbc", "-e", "-p", password], stdout=subprocess.PIPE, stderr=subprocess.PIPE, input=data)
	else:
		encrypted_res = subprocess.run(["openssl", "des-cbc", "-e", "-pass", b"pass:" + password], stdout=subprocess.PIPE, stderr=subprocess.PIPE, input=data)
	if (encrypted_res.stderr != b''):
		print (colored("Error", 'red'), " : Encrypted stderr not empty (", encrypted_res.stderr, ") [", current_test_nbr, "]")

	if (encrypt_with_mine == True):
		decrypted_res = subprocess.run(["openssl", "des-cbc", "-d", "-pass", b"pass:" + password], stdout=subprocess.PIPE, stderr=subprocess.PIPE, input=encrypted_res.stdout)
	else:
		decrypted_res = subprocess.run([PROGRAM_NAME, "des-cbc", "-d", "-p", password], stdout=subprocess.PIPE, stderr=subprocess.PIPE, input=encrypted_res.stdout)
	if (decrypted_res.stderr != b''):
		print (colored("Error", 'red'), " : Decrypted stderr not empty (", encrypted_res.stderr, ") [", current_test_nbr, "]")

	if (decrypted_res.stdout != data):
		print (colored("Error", 'red'), " : [", data, "] != [", decrypted_res.stdout, "] [", current_test_nbr, "]")
	else:
		print (colored("OK", 'green'), "[", current_test_nbr, "]")
		return (True)
	current_nfalse += 1
	return (False)

def check_base64_against_real(data, encrypt_with_mine=True):
	global current_nfalse
	global current_test_nbr

	current_test_nbr += 1
	if (encrypt_with_mine == True):
		encrypted_res = subprocess.run([PROGRAM_NAME, "base64", "-e"], stdout=subprocess.PIPE, stderr=subprocess.PIPE, input=data)
	else:
		encrypted_res = subprocess.run(["openssl", "base64", "-e"], stdout=subprocess.PIPE, stderr=subprocess.PIPE, input=data)
	if (encrypted_res.stderr != b''):
			print (colored("Error", 'red'), " : Encrypted stderr not empty (", encrypted_res.stderr, ") [", current_test_nbr, "]")
	else:
		if (encrypt_with_mine == True):
			decrypted_res = subprocess.run(["openssl", "base64", "-d"], stdout=subprocess.PIPE, stderr=subprocess.PIPE, input=encrypted_res.stdout)
		else:
			decrypted_res = subprocess.run([PROGRAM_NAME, "base64", "-d"], stdout=subprocess.PIPE, stderr=subprocess.PIPE, input=encrypted_res.stdout)
		if (decrypted_res.stderr != b''):
			print (colored("Error", 'red'), " : Decrypted stderr not empty (", encrypted_res.stderr, ") [", current_test_nbr, "]")
		elif (decrypted_res.stdout != data):
			print (colored("Error", 'red'), " : [", data, "] != [", decrypted_res.stdout, "] [", current_test_nbr, "]")
		else:
			print (colored("OK", 'green'), "[", current_test_nbr, "]")
			return (True)
	current_nfalse += 1
	return (False)
