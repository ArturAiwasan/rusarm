#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <vector>
#include <map>

#include <locale>
#include <codecvt>

class vortaro {
//~ #include <iostream>
//~ #include <fstream>
//~ #include <sstream>
//~ #include <unordered_map>
//~ #include <string>
//~ #include <vector>
//~ #include <map>

public:
  struct CaseForms {
  std::string nominative;
  std::string ablative;
  std::string dative;
  std::string instrumental;
  std::string locative;
  std::string plnominative;
  std::string plablative;
  std::string pldative;
  std::string plinstrumental;
  std::string pllocative;
 };
 std::unordered_map<std::string, CaseForms> dictionary;

 std::vector<std::string> splitString(const std::string& line, char delimiter) {
  std::vector<std::string> tokens;
  std::stringstream ss(line);
  std::string token;
  while (std::getline(ss, token, delimiter)) {
      tokens.push_back(token);
  }
  return tokens;
 };

 void getWordsFromFile() {
  std::ifstream inputFile("./words.txt");
  if (inputFile.is_open()) {
   std::string line;
   while (std::getline(inputFile, line)) {
    std::vector<std::string> tokens = splitString(line, '\n');
    if (tokens.size() == 1) {
     std::string word = tokens[0];
     CaseForms forms;
     forms.nominative = word;
     forms.ablative = word + "иц";
     forms.dative = word + "и";
     forms.instrumental = word + "ов";
     forms.locative = word + "ум";
     forms.plnominative = word + "нер";
     forms.plablative = word + "нериц";
     forms.pldative = word + "нери";
     forms.plinstrumental = word + "неров";
     forms.pllocative = word + "нерум";
     dictionary[word] = forms;
    } else {
    }
   }
   inputFile.close();
  } else {
   std::cout << "NE NAJDENO" << std::endl;
  };
};

 void getWord(std::string word) {
  //~ getWordsFromFile();
  if (dictionary.find(word) != dictionary.end()) {
   CaseForms forms = dictionary[word];
   std::cout << "Slovo: " << word << "\n" << std::endl;
   std::cout << "Singular:" << std::endl;
   std::cout << "Nominativ: " << forms.nominative << std::endl;
   std::cout << "Ablativ: " << forms.ablative << std::endl;
   std::cout << "Dativ: " << forms.dative << std::endl;
   std::cout << "Instrumental: " << forms.instrumental << std::endl;
   std::cout << "Lokativ: " << forms.locative << std::endl;
   std::cout << "=========" << std::endl;
   std::cout << "Plural:" << std::endl;
   std::cout << "Nominativ: " << forms.plnominative << std::endl;
   std::cout << "Ablativ: " << forms.plablative << std::endl;
   std::cout << "Dativ: " << forms.pldative << std::endl;
   std::cout << "Instrumental: " << forms.plinstrumental << std::endl;
   std::cout << "Lokativ: " << forms.pllocative << std::endl;

   std::cout << "\nPO ARMJANSKI" << "\n" << std::endl;

   std::cout << "Slovo: " << transliterateToArmenian(word) << "\n" << std::endl;
   std::cout << "Singular:" << std::endl;
   std::cout << "Nominativ: " << transliterateToArmenian(forms.nominative) << std::endl;
   std::cout << "Ablativ: " << transliterateToArmenian(forms.ablative) << std::endl;
   std::cout << "Dativ: " << transliterateToArmenian(forms.dative) << std::endl;
   std::cout << "Instrumental: " << transliterateToArmenian(forms.instrumental) << std::endl;
   std::cout << "Lokativ: " << transliterateToArmenian(forms.locative) << std::endl;
   std::cout << "=========" << std::endl;
   std::cout << "Plural:" << std::endl;
   std::cout << "Nominativ: " << transliterateToArmenian(forms.plnominative) << std::endl;
   std::cout << "Ablativ: " << transliterateToArmenian(forms.plablative) << std::endl;
   std::cout << "Dativ: " << transliterateToArmenian(forms.pldative) << std::endl;
   std::cout << "Instrumental: " << transliterateToArmenian(forms.plinstrumental) << std::endl;
   std::cout << "Lokativ: " << transliterateToArmenian(forms.pllocative) << std::endl;
  } else {
   std::cout << "Slovo ne najdeno v baze dannyh." << std::endl;
  }
 };

 std::string transliterateToArmenian(const std::string& text) {
  std::map<char, std::string> translitDict = {
   {'а', "ա"}, {'б', "բ"}, {'в', "վ"}, {'г', "գ"}, {'д', "դ"}, {'е', "ե"}, {'ё', "ե"},
   {'ж', "ժ"}, {'з', "զ"}, {'и', "ի"}, {'й', "յ"}, {'к', "կ"}, {'л', "լ"}, {'м', "մ"},
   {'н', "ն"}, {'о', "ո"}, {'п', "պ"}, {'р', "ր"}, {'с', "ս"}, {'т', "տ"}, {'у', "ու"},
   {'ф', "ֆ"}, {'х', "խ"}, {'ц', "ծ"}, {'ч', "ճ"}, {'ш', "շ"}, {'щ', "շ"}, {'ъ', "ը"},
   {'ы', "յ"}, {'ь', "բ"}, {'э', "ե"}, {'ю', "յու"}, {'я', "յա"},
   {'А', "Ա"}, {'Б', "Բ"}, {'В', "Վ"}, {'Г', "Գ"}, {'Д', "Դ"}, {'Е', "Ե"}, {'Ё', "Ե"},
   {'Ж', "Ժ"}, {'З', "Զ"}, {'И', "Ի"}, {'Й', "Յ"}, {'К', "Կ"}, {'Л', "Լ"}, {'М', "Մ"},
   {'Н', "Ն"}, {'О', "Ո"}, {'П', "Պ"}, {'Р', "Ր"}, {'С', "Ս"}, {'Т', "Տ"}, {'У', "Ու"},
   {'Ф', "Ֆ"}, {'Х', "Խ"}, {'Ц', "Ծ"}, {'Ч', "Ճ"}, {'Ш', "Շ"}, {'Щ', "Շճ"}, {'Ъ', "Ը"},
   {'Ы', "Յ"}, {'Ь', "Բ"}, {'Э', "Ե"}, {'Ю', "Յու"}, {'Я', "Յա"}
   //~ {'а', "\u0561"}, {'б', "\u0562"}, {'в', "\u057E"}, {'г', "\u0563"}, {'д', "\u0564"}, {'е', "\u0565"}, {'ё', "\u0565"},
   //~ {'ж', "\u056A"}, {'з', "\u0566"}, {'и', "\u056B"}, {'й', "\u0575"}, {'к', "\u056F"}, {'л', "\u056C"}, {'м', "\u0574"},
   //~ {'н', "\u0576"}, {'о', "\u0578"}, {'п', "\u057A"}, {'р', "\u0580"}, {'с', "\u057D"}, {'т', "\u057F"}, {'у', "\u0578\u0582"},
   //~ {'ф', "\u0586"}, {'х', "\u056D"}, {'ц', "\u056E"}, {'ч', "\u0573"}, {'ш', "\u0577"}, {'щ', "\u0577\u0573"}, {'ъ', "\u0568"},
   //~ {'ы', "\u056B"}, {'ь', "\u0575"}, {'э', "\u0565"}, {'ю', "\u0575\u0578\u0582ւ"}, {'я', "\u0575\u0561"},
   //~ {'А', "Ա"}, {'Б', "Բ"}, {'В', "Վ"}, {'Г', "Գ"}, {'Д', "Դ"}, {'Е', "Ե"}, {'Ё', "Ե"},
   //~ {'Ж', "Ժ"}, {'З', "Զ"}, {'И', "Ի"}, {'Й', "Յ"}, {'К', "Կ"}, {'Л', "Լ"}, {'М', "Մ"},
   //~ {'Н', "Ն"}, {'О', "Ո"}, {'П', "Պ"}, {'Р', "Ր"}, {'С', "Ս"}, {'Т', "Տ"}, {'У', "Ու"},
   //~ {'Ф', "Ֆ"}, {'Х', "Խ"}, {'Ц', "Ծ"}, {'Ч', "Ճ"}, {'Ш', "Շ"}, {'Щ', "Շճ"}, {'Ъ', "Ը"},
   //~ {'Ы', "Յ"}, {'Ь', "Բ"}, {'Э', "Ե"}, {'Ю', "Յու"}, {'Я', "Յա"}
  };

  std::string result = u8"";

  for (char c : text) {
   if (translitDict.find(c) != translitDict.end()) {
    result += translitDict[c];
   } else {
    result += c;
   }
  };

  return result;
 }
};

int main(int argc, char** argv) {
 vortaro Slovar;
 Slovar.getWordsFromFile();
 Slovar.getWord(argv[1]);

 return 0;
}

