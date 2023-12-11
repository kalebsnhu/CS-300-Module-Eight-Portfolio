//============================================================================
//  - Name: Kaleb Ward
//  - Date: 12-9-23
//  - Description: This program reads course files in the .csv file type and 
// formats them into course objects and can be utilized to print various
// features throughout the program. You can search for specific courses, all
// courses, and print the pre-requisites for either one.
//============================================================================

// Include all utility libraries we will utilize
#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>

// Set the namespace to std so we can utilize functions throughout.
using namespace std;

//============================================================================
//  Function: BinarySearchTree::printAllCourses(Node* node, bool printPreReqs)
//  Args: Node* node, printPreReqs (if they wish to print pre-requisites)
//  Description: Prints all courses throughout the BinarySearchTree and traverses
//  all nodes within the BinarySearchTree and prints the courses and pre-requisites.
//============================================================================
void BinarySearchTree::printAllCourses(Node* node, bool printPreReqs) {
    // If the node is not null then we need to print the courses.
    if (node != nullptr) {
        // Traverse to the left and print all courses.
        printAllCourses(node->left, printPreReqs);
        cout << "(=) Course: " << node->course.courseNumber << ", Name: " << node->course.courseName << endl;
        // If course pre-requisites are wanted to be printed then we need to print.
        if (printPreReqs == true) {
            string tempPreReqs;
            for (string preRequisite : node->course.preReqs) {
                // If the pre-requisite contains one or more pre-requisites.
                if (preRequisite == node->course.preReqs.back()) {
                    tempPreReqs = tempPreReqs + preRequisite;
                }
                // Else then add the string onto itself with a divider ",".
                else {
                    tempPreReqs = tempPreReqs + preRequisite + ",";
                }
            }
            // If the course contains pre-requisites then we need to remove the "'s from the string to make it more legible.
            if (tempPreReqs.length() > 0) {
                // Find the "'s within the string and replace with 0
                if (tempPreReqs.find("\"") != std::string::npos) {
                    tempPreReqs.replace(0, 1, "");
                    tempPreReqs.replace(tempPreReqs.length() - 1, tempPreReqs.length(), "");
                }
                // Print the course pre-requisites if needed.
                cout << "(-) Pre-Requisites: ";
                cout << tempPreReqs;
                cout << endl;
            }
            cout << endl;
        }
        // Traverse to the right and print all courses.
        printAllCourses(node->right, printPreReqs);
    }
}