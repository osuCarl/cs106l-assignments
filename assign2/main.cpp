/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <sstream>

#include "utils.h"

std::string kYourName = "OSU CARL"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  std::ifstream ifs(filename);
  std::set<std::string> applicants;

  if (ifs.is_open()) {
    std::string line;
    while (std::getline(ifs, line)) {
      applicants.insert(line);
    }
  }
  
  ifs.close();
  return applicants;
}
bool compare_initials_helper(const std::string name1, const std::string name2) {
  std::pair<std::string, std::string> p1;
  std::stringstream ss1(name1);
  ss1 >> p1.first; ss1 >> p1.second;

  std::pair<std::string, std::string> p2;
  std::stringstream ss2(name2);
  ss2 >> p2.first; ss2 >> p2.second;

  return p1.first.at(0) == p2.first.at(0)
        && p1.second.at(0) == p2.second.at(0);
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  std::queue<const std::string*> matches;
  for (const auto& candidate : students) {
    if (compare_initials_helper(name, candidate)) {
      matches.push(&candidate);
    }
  }

  return matches;
}



/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  std::string result{""};
  if (matches.empty()) {
    return {"NO STUDENT FOUND."};
  } else {
    return *matches.back();
  }
}

/* #### Please don't modify this call to the autograder! #### */
int main() { return run_autograder(); }
