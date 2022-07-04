import sys
import requests
from bs4 import BeautifulSoup


def main():
    print("start parser")
    try:
        id = sys.argv[1]
        code = "bb036e49-cf01-4846-9206-ba5baf479927"
        url = f"http://elibrary.ru/projects/API-NEB/API_NEB.aspx?ucode={code}&sid=024&authorid={id}"
        data = requests.get(url)
        #print(data, f"{url}&authorid={id}")
        #print(data.text)
        soup = BeautifulSoup(data.text, "html.parser")

        autorId = soup.find('authorid').text
        lastName = soup.find("lastname").text
        firstName = soup.find("firstname").text
        secondName = soup.find("secondname").text
        city = soup.find("city").text
        orgName = soup.find("orgname").text
        link = f"http://elibrary.ru/author_profile.asp?id={autorId}"

        with open("jog.txt", 'a', encoding='utf-8') as f:
            f.write(f"{autorId} | {lastName} | {firstName} | {secondName} | {city} | {orgName} | {link}\n")
    except:
        print("error")

if __name__ == '__main__':
    main()
