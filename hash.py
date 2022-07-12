# test script
"""
    Testing the hashing functions for the validity of the result
    https://github.com/BinaryBun/Parser/blob/2642554382d6921f894f6bbe6b41969872a66e50/Hash.py#L37
    https://github.com/BinaryBun/Parser/blob/2642554382d6921f894f6bbe6b41969872a66e50/Hash.py#L17
"""
import hashlib
import random
import string
global_token = ""


def get_from_server():
	global global_token
	# переписать
	token = ''.join(random.choice(string.ascii_lowercase) for i in range(8))
	global_token = token
	return token

def server(data):
	global global_token
	# user data
	user_data = {"maxim": md5("some_passwd")}
	print("Data in server:", user_data, f"token: {global_token}")

	#check
	check_passwd = md5(global_token + user_data[data[0]])
	print(f"Check passwd: {check_passwd}")
	print(20*'=')
	print(f"Result: {check_passwd == data[-1]}")
	print(20*'=')

def md5(str):
	# Предположительно по умолчанию UTF-8
	hash_object = hashlib.md5(str.encode())
	return hash_object.hexdigest()

def main():
	# start connection (1)
	serv_token = get_from_server()  # step 2
	print(f"Data in step 2: '{serv_token}'")  # check data step 2

	# get login & password
	login, passwd = "maxim", "some_passwd"
	passwd = serv_token + md5(passwd)
	passwd = md5(passwd)

	# send datat to server
	send_data = [login, passwd]
	print(f"Data in step 3: {send_data}")
	server(send_data)

	""" Допустим мы перехватили на 3 шаге данные (send_data) и отправляем их на сервер """
	print('\n' + 10*"-" + " HACK " + 10*'-')
	hack_token = get_from_server()  # (2)
	print(f"Hack step 2: '{hack_token}'")
	hack_data = send_data  # hack step (3)
	print(f"Hack step 3: {hack_data}")
	server(send_data)  # (3)

def tests():
    # test 1
    print(md5("maxim") == "95ac3c545fa3f9c81939f8fa4d0511ca")
    print(md5("aa") == "4124bc0a9335c27f086f24ba207a4912")
    print(md5("bb") == "21ad0bd836b90d08f4cf640b4c298e7c")
    print(md5("ccc") == "9df62e693988eb4e1e1444ece0578579")

    # test 2
    '''
        Must return different tokens
    '''
    data = [get_from_server() for i in range(10)]
    print(f"\n{len(data) == len(set(data))}")


if __name__ == '__main__':
	tests()
