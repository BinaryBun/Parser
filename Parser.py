from selenium import webdriver
from time import *
import os

def main():
	def rec():
		pass

	def find_autor(browser, name):
		try:
			# find text box
			name_box = browser.find_element_by_xpath('//input[@id="surname"]') 
			name_box.click()
			name_box.clear()
			name_box.send_keys(name)

			# find button
			button = browser.find_element_by_xpath('//div[text()="Поиск"]')
			button.click()

			# print data
			try:  # null autor
				browser.find_element_by_xpath('//font[text()="Не найдено авторов, удовлетворяющих условиям поиска"]')
				print("Нету автора")
			except:
				print("Name:", 
					  browser.find_element_by_xpath('//table[@id="restab"]/child::*//tr[@id]//td[@class="midtext"][1]//b').text)
				print("Publications:", 
					  browser.find_element_by_xpath('//table[@id="restab"]/child::*//tr[@id]//td[@class="midtext"][2]').text)
				print("Index:", 
					  browser.find_element_by_xpath('//table[@id="restab"]/child::*//tr[@id]//td[@class="midtext select-tr-right"]').text)
			print(50*'-', '\n')


		except:
			'''
			скачать - распознать - удалить
			'''
			print("Капча")
			browser.find_element_by_xpath('//form').click()
			sleep(10)
			try:
				# прошли капчу
				browser.find_element_by_xpath('//span[@aria-checked="true"]')
				print("Капча пойдена")
				sleep(.5)
				browser.find_element_by_xpath('//input[@value="Продолжить"]').click()
			except:
				print("КАПЧА НЕ ПРОЙДЕНА")


			sleep(10)
			


	# get connect
	browser = webdriver.Chrome()
	browser.get("https://www.elibrary.ru/authors.asp")

	name = ["Платон", "Вероника", "Диана", "Ева", "Анастасия", "Дмитрий", 
			"Софья", "Елисей", "Александр", "Ксения", "Мария", "Екатерина", 
			"Анна", "Степан", "Михаил", "Агния", "Ульяна", "Максим", "Лев", 
			"Варвара", "Виктория", "Никита", "Валерия", "Алиса", "Алина", 
			"Даниэль", "Оливия", "Борис", "Полина", "Захар", "Мирон", "Тимофей", 
			"Виолетта", "София", "Роман", "Сафия", "Амелия", "Олег", "Александра", 
			"Эмилия", "Арсений", "Елизавета", "Сабина", "Кристина", "Ярослав", 
			"Стефания", "Милана", "Алеся", "Эмир", "Макар"]

	for i in range(len(name)):
		print(i+1)
		find_autor(browser, name[i])

if __name__ == '__main__':
	main()	