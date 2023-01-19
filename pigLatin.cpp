// Copyright (c) 2023 Zaida Hammel All rights reserved
//
// Created by: Zaida Hammel
// Created on: Dec 2022
// This program converts the sentence to Pig Latin

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

std::string pigLatin(std::string sentence) {
    // This function converts normal text to Pig Latin
    // keeping strtok, the variable-length array and strcpy for simplicity
    int sentenceLength = sentence.length();
    char sentenceChars[sentenceLength + 1];
    std::vector<std::string> newWords;
    std::vector<std::string> words;
    std::string newWord;
    std::string newSentence;

    /* https://www.programiz.com/c-programming/
    library-function/string.h/strcpy */
    strcpy(sentenceChars, sentence.c_str());

    /* https://www.tutorialspoint.com/c_standard_library
    /c_function_strtok.htm */
    // get the first token
    char *token = strtok(sentenceChars, " ");

    // walk through other tokens
    while (token != NULL) {
        std::string word = std::string(token);
        words.push_back(word);
        token = strtok(NULL, " ");
    }

    // conversion
    for (std::string word : words) {
        newWord = (word.erase(0, 1) + word.substr(0, 1) + "ay");
        newWords.push_back(newWord);
    }

    // joining strings
    newSentence = "";
    for (std::string word : newWords) {
        newSentence += word + " ";
    }

    /* https://stackoverflow.com/questions/313970/
    how-to-convert-an-instance-of-stdstring-to-lower-case */
    std::transform(newSentence.begin(), newSentence.end(), newSentence.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    return newSentence;
}

int main() {
    // This function is the main function
    std::string user_input;

    std::cout << "Pig Latin Converter" << std::endl;

    // input
    std::cout << "Enter a sentence: ";
    getline(std::cin, user_input);

    // process & output
    std::cout << "\n"
              << pigLatin(user_input) << std::endl;

    std::cout << "\nDone." << std::endl;
}
