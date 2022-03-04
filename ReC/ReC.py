'''import speech_recognition as sr 
import os 
from pydub import AudioSegment
from pydub.silence import split_on_silence

r = sr.Recognizer()

def get_large_audio_transcription(path):

    sound = AudioSegment.from_wav(path)  
    chunks = split_on_silence(sound,
        min_silence_len = 500,
        silence_thresh = sound.dBFS-14,
        keep_silence=500,
    )
    folder_name = "audio-chunks"
    if not os.path.isdir(folder_name):
        os.mkdir(folder_name)
    whole_text = ""
    for i, audio_chunk in enumerate(chunks, start=1):
        chunk_filename = os.path.join(folder_name, f"chunk{i}.wav")
        audio_chunk.export(chunk_filename, format="wav")
        with sr.AudioFile(chunk_filename) as source:
            audio_listened = r.record(source)
            try:
                text = r.recognize_google(audio_listened)
            except sr.UnknownValueError as e:
                print("Error:", str(e))
            else:
                text = f"{text.capitalize()}. "
                #print(chunk_filename, ":", text)Do
                whole_text += text
    return whole_text
#path = "audio.wav"
#print("\nFull text:", get_large_audio_transcription(path))'''

from selenium import webdriver
import pyautogui
from time import *

def main():
    browser = webdriver.Chrome()
    browser.get("https://speech-to-text-demo.ng.bluemix.net/")
    browser.find_element_by_xpath('//button[2]').click()
    sleep(2)
    pyautogui.write("Downloads")
    pyautogui.hotkey("enter")
    pyautogui.write("audio (3).mp3")
    pyautogui.hotkey("enter")
    sleep(8)
    # get text
    text = browser.find_element_by_xpath('//div[@class="tab-panels--tab-content"]//span').text 
    print(text)

if __name__ == '__main__':
    main()
