/**
 * Driver file for CS 210 Program 1
 * @author Cameron Cobb <ccobb4974@sdsu.edu>
 * @date Sept 20, 2022
 *
 * This program creates a function called sortCarInventory that takes in two vector parameters: a vector called carInventory that lists an unsorted
 * inventory of cars and a vector called promotionOrder that lists the order in which carInventory should be sorted to. This function uses two for loops 
 * to iterate through carInventory twice, keeping track of which elements to swap according to the values of their respective elements The index is called swapIndex and it is used to swap the current element if another element is either
 * promotionOrder.at(0) or promotionOrder.at(1) depending on whcih loop it is. This function operates in O(N) complexity becausee only two for loops are used and they are not nested.
 */


 /* Single Programmer Affidavit
I the undersigned promise that the submitted assignment is my own work. While I was 
free to discuss ideas with others, the work contained is my own. I recognize that 
should this not be the case; I will be subject to penalties as outlined in the course 
syllabus. 
Name: Cameron Cobb
Red ID: 826504686
*/

#include "sortcar.h"

/**
 * 
 * 
 * 
 * @brief sort car inventory
 * 
 * @param carInventory      input car inventory array
 * @param promotionOrder    car promotion order
 * @return vector<string>   sorted car inventory according to the car promotion order
 * 
 * Time complexity has to be linear: O(N), N is the size/length of the input car inventory array
 * Space complexity has to be constant: O(1), hint: sorting can be done by mutating 
 *                                      the input car inventory array.
 */

vector<string> SortCar::sortCarInventory(vector<string> carInventory, vector<string> promotionOrder) {

// swapIndex is the index that represents the current element that needs to be swapped. The loop variable i will be used to perform the swap. This is non
// input data.
int swapIndex = 0;
// firstPromotion represents the first element in promotionOrder vector. This is non-input data.
string firstPromotion = promotionOrder.at(0);
// secondPromotion represents the second element in promotionOrder vector. This is non-input data.
string secondPromotion = promotionOrder.at(1);
//temp is a temporary string variable used to perform swap. This is non-input data.
string temp = "";

    /**
     * This loop involves a sorted portion and an unsortion portion. The unsorted portion is all elements after the int variable swapIndex, and the loop variable i and
     * its associated elements are the variables that need to be swapped with swapIndex to make a sortion portion. The loop variable i, therefore 
     * navigates through the assumed unsorted potion of the vector, finding elements that are equal to firstPromotion.
     * This for loop iterates through the entire carInventory vector. carInventory.size() is the length of the vector, represented as N.
     * This for loop specifically sorts the array according to the first element of promotionOrder, or firstPromotion. The elements in carInventory
     * that are equal to firstPromotoion will be the first occuring elements in carInventory after this loop ends.
     */
    for (unsigned int i = 0; i < carInventory.size(); ++i) {
        /**
         * This condition determines if the current element, which is carInventory(i), is equal to the first element in promotionOrder, or firstPromotion.
         * If it is, then a swap will be performed with the element at index swapIndex, which is the element after the sorted portion of the list. Therefore
         * everything to the left of swapIndex is assumed to be sorted. When this if statement executes (meaning the above conditions are met),
         * then the string "temp" variable is assigned with carInventory.at(i) so that when carInventory.at(i) is assigned to carInventory.at(swapIndex),
         * carInventory.at(swapIndex) can be assigned to carInventory.at(i). The "temp" variable acts as a temporary placeholder to hold the other element that 
         * needs to be swapped with. A swap cannot be performed between these two elements without this "temp" string variable. Finally, swapIndex is incremented to indicate that
         * an element has been swapped to the sorted portion of the carInventory vector.
         * 
         */
        if (carInventory.at(i) == firstPromotion) {
            temp = carInventory.at(i);
            // This statement assigns the current element with the element that is intended to be swapped with, since it does not equal firstPromotion.
            carInventory.at(i) = carInventory.at(swapIndex);
            // This statement assigns element at swapIndex, which is the element after the last sorted element, with an element equal to firstPromotion from the unsorted portion of carInventory.
            carInventory.at(swapIndex) = temp;
            ++swapIndex;
        }
    }

    /**
     * Similar to the first loop, this loop involves two variables: the int variable swapIndex and the int loop variable i. This for loops starts
     * at the last unsorted element, which is swapIndex, since the previous for loop already sorted the vector according to the firstPromotion.
     * The for loop will perform similarily, starting at the beginning of the unsorted portion and iterating through the rest of carInventory once
     * again. All secondPromotion elements will be swapped from the unsorted portion with swapIndex so that they occur together starting at swapIndex in this loop. 
     * A swap will be performed since swapIndex will not be equal to secondPromotion. A temporary string variable called "temp" will be used
     * to perform the swap between carInventory.at(swapIndex) and carInventory.at(i). After this loop is terminated and once all of the elements equal to secondPromotion
     * are grouped together after the elements equal to firstPromotion, then the remaining elements in the list will be sorted as well, which will be equal
     * to promotionOrder.at(2).
     */
    for (unsigned int i = swapIndex; i < carInventory.size(); ++i) {
        /**
         * This condition is similar to the first condition in the first loop, except that the target element to swap is the second element in 
         * promotionOrder.
         */
        if (carInventory.at(i) == secondPromotion) {
            // This variable is a placeholder to allow the swap between carInventory.at(i) and carInventory.at(swapIndex).
            temp = carInventory.at(i);
            // This assigns the current element, which is equal to secondPromotion, in the unsorted part of the vector with the element at swapIndex, or the element that is considered
            // unsorted based on its location. carInventory.at(i) must be swapped so that the proper element can be moved to its correpsonding sorted area.
            carInventory.at(i) = carInventory.at(swapIndex);
            // This statement assigns the unsorted element back to the unsorted portion of the list. 
            carInventory.at(swapIndex) = temp;
            ++swapIndex;
        }
    }
    return carInventory;

}