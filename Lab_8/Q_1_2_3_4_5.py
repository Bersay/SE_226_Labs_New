from abc import ABC, abstractmethod
import string


class AbstractClass(ABC):
    def __init__(self, address):
        self.address = address

    @abstractmethod
    def calculateFreqs(self):
        pass


class ListCount(AbstractClass):
    def calculateFreqs(self):
        with open(self.address, 'r') as file:
            content = file.read().lower()
            frequencies = []
            for letter in string.ascii_lowercase:
                count = content.count(letter)
                if count > 0:
                    frequencies.append(f"{letter} = {count}")
            print(frequencies)


class DictCount(AbstractClass):
    def calculateFreqs(self):
        with open(self.address, 'r') as file:
            content = file.read().lower()
            frequencies = {}
            for letter in string.ascii_lowercase:
                count = content.count(letter)
                if count > 0:
                    frequencies[letter] = count
            print(frequencies)


list_count = ListCount('C:/Users/bersay/Downloads/weirdWords.txt')
list_count.calculateFreqs()

dict_count = DictCount('C:/Users/bersay/Downloads/weirdWords.txt')
dict_count.calculateFreqs()
