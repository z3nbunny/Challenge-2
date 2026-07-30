/* *************************************************
* Name: David McGovern
* Assignment: Challenge 2: Queues
* Purpose: Provides exhaustive testing for the linked
*          FIFO and LIFO Queue ADT.
************************************************* */

#include "main.h"

int main() {
/* *************************************************
* Creates FIFO and LIFO queue objects and performs
* explicit, boundary, reuse, and stress testing on
* every public Queue operation.
*
* @param : none
* @exception : none
* @return int : 0 on successful program completion
* @note : All testing is intentionally contained in main.
* ************************************************* */

    // Test constants
    const int FIRST_ID = 10;
    const int SECOND_ID = 20;
    const int THIRD_ID = 30;
    const int SINGLE_ID = 77;
    const int REUSE_ID = 88;
    const int DUPLICATE_ID = 55;
    const int INVALID_NEGATIVE_ID = -5;
    const int MISSING_ID = 999;
    const int INVALID_ZERO_ID = 0;
    const int THREE_ITEMS = 3;
    const int TWO_ITEMS = 2;
    const int STRESS_COUNT = 1000;
    const int STRESS_BASE_ID = 1000;

    const std::string FIRST_INFO = "Alpha";
    const std::string SECOND_INFO = "Beta";
    const std::string THIRD_INFO = "Gamma";
    const std::string SINGLE_INFO = "Single Item";
    const std::string REUSE_INFO = "Reuse Item";
    const std::string DUPLICATE_FIRST_INFO = "First Duplicate";
    const std::string DUPLICATE_SECOND_INFO = "Second Duplicate";
    const std::string STRESS_PREFIX = "Stress Data ";

    // Queue objects
    Queue fifo_queue(FIFO);
    Queue lifo_queue(LIFO);
    Queue fifo_stress(FIFO);
    Queue lifo_stress(LIFO);

    // Testing variables
    Data returned_data;
    bool operation_result = false;
    bool phase_success = true;
    int tests_run = 0;
    int tests_passed = 0;
    int expected_id = 0;
    std::string expected_information = "";

    returned_data.id = 0;
    returned_data.information = "";

    std::cout << "==========================================" << std::endl;
    std::cout << "       QUEUE ADT TESTING TESTBED          " << std::endl;
    std::cout << "==========================================" << std::endl;


    // =========================================================
    // PHASE 1: INITIAL EMPTY FIFO QUEUE
    // =========================================================
    std::cout << std::endl;
    std::cout << "--- PHASE 1: INITIAL EMPTY FIFO QUEUE ---" << std::endl;

    tests_run++;
    if (fifo_queue.count() == 0) {
        tests_passed++;
        std::cout << "PASS: FIFO count is initially 0." << std::endl;
    } else {
        std::cout << "FAIL: FIFO count is not initially 0." << std::endl;
    }

    tests_run++;
    if (fifo_queue.peek() == -1) {
        tests_passed++;
        std::cout << "PASS: FIFO peek returns -1 when empty." << std::endl;
    } else {
        std::cout << "FAIL: FIFO peek did not return -1 when empty." << std::endl;
    }

    tests_run++;
    if (!fifo_queue.exists(FIRST_ID)) {
        tests_passed++;
        std::cout << "PASS: FIFO exists reports false when empty." << std::endl;
    } else {
        std::cout << "FAIL: FIFO exists reported true when empty." << std::endl;
    }

    tests_run++;
    if (fifo_queue.find(FIRST_ID) == -1) {
        tests_passed++;
        std::cout << "PASS: FIFO find returns -1 when empty." << std::endl;
    } else {
        std::cout << "FAIL: FIFO find did not return -1 when empty." << std::endl;
    }

    returned_data.id = FIRST_ID;
    returned_data.information = FIRST_INFO;
    operation_result = fifo_queue.pull(returned_data);

    tests_run++;
    if (!operation_result &&
        returned_data.id == -1 &&
        returned_data.information.empty()) {
        tests_passed++;
        std::cout << "PASS: FIFO pull safely handles an empty queue."
                  << std::endl;
    } else {
        std::cout << "FAIL: FIFO pull did not safely handle an empty queue."
                  << std::endl;
    }

    fifo_queue.clear();

    tests_run++;
    if (fifo_queue.count() == 0 && fifo_queue.peek() == -1) {
        tests_passed++;
        std::cout << "PASS: FIFO clear is safe on an empty queue."
                  << std::endl;
    } else {
        std::cout << "FAIL: FIFO clear changed the empty state."
                  << std::endl;
    }


    // =========================================================
    // PHASE 2: INITIAL EMPTY LIFO QUEUE
    // =========================================================
    std::cout << std::endl;
    std::cout << "--- PHASE 2: INITIAL EMPTY LIFO QUEUE ---" << std::endl;

    tests_run++;
    if (lifo_queue.count() == 0) {
        tests_passed++;
        std::cout << "PASS: LIFO count is initially 0." << std::endl;
    } else {
        std::cout << "FAIL: LIFO count is not initially 0." << std::endl;
    }

    tests_run++;
    if (lifo_queue.peek() == -1) {
        tests_passed++;
        std::cout << "PASS: LIFO peek returns -1 when empty." << std::endl;
    } else {
        std::cout << "FAIL: LIFO peek did not return -1 when empty."
                  << std::endl;
    }

    tests_run++;
    if (!lifo_queue.exists(FIRST_ID)) {
        tests_passed++;
        std::cout << "PASS: LIFO exists reports false when empty."
                  << std::endl;
    } else {
        std::cout << "FAIL: LIFO exists reported true when empty."
                  << std::endl;
    }

    tests_run++;
    if (lifo_queue.find(FIRST_ID) == -1) {
        tests_passed++;
        std::cout << "PASS: LIFO find returns -1 when empty." << std::endl;
    } else {
        std::cout << "FAIL: LIFO find did not return -1 when empty."
                  << std::endl;
    }

    returned_data.id = FIRST_ID;
    returned_data.information = FIRST_INFO;
    operation_result = lifo_queue.pull(returned_data);

    tests_run++;
    if (!operation_result &&
        returned_data.id == -1 &&
        returned_data.information.empty()) {
        tests_passed++;
        std::cout << "PASS: LIFO pull safely handles an empty queue."
                  << std::endl;
    } else {
        std::cout << "FAIL: LIFO pull did not safely handle an empty queue."
                  << std::endl;
    }

    lifo_queue.clear();

    tests_run++;
    if (lifo_queue.count() == 0 && lifo_queue.peek() == -1) {
        tests_passed++;
        std::cout << "PASS: LIFO clear is safe on an empty queue."
                  << std::endl;
    } else {
        std::cout << "FAIL: LIFO clear changed the empty state."
                  << std::endl;
    }


    // =========================================================
    // PHASE 3: INVALID PUSH OPERATIONS
    // =========================================================
    std::cout << std::endl;
    std::cout << "--- PHASE 3: INVALID PUSH OPERATIONS ---" << std::endl;

    operation_result = fifo_queue.push(INVALID_ZERO_ID, FIRST_INFO);

    tests_run++;
    if (!operation_result && fifo_queue.count() == 0) {
        tests_passed++;
        std::cout << "PASS: FIFO rejected id 0." << std::endl;
    } else {
        std::cout << "FAIL: FIFO accepted id 0." << std::endl;
    }

    operation_result = fifo_queue.push(INVALID_NEGATIVE_ID, FIRST_INFO);

    tests_run++;
    if (!operation_result && fifo_queue.count() == 0) {
        tests_passed++;
        std::cout << "PASS: FIFO rejected a negative id." << std::endl;
    } else {
        std::cout << "FAIL: FIFO accepted a negative id." << std::endl;
    }

    operation_result = fifo_queue.push(FIRST_ID, "");

    tests_run++;
    if (!operation_result && fifo_queue.count() == 0) {
        tests_passed++;
        std::cout << "PASS: FIFO rejected empty information." << std::endl;
    } else {
        std::cout << "FAIL: FIFO accepted empty information." << std::endl;
    }

    operation_result = lifo_queue.push(INVALID_ZERO_ID, FIRST_INFO);

    tests_run++;
    if (!operation_result && lifo_queue.count() == 0) {
        tests_passed++;
        std::cout << "PASS: LIFO rejected id 0." << std::endl;
    } else {
        std::cout << "FAIL: LIFO accepted id 0." << std::endl;
    }

    operation_result = lifo_queue.push(INVALID_NEGATIVE_ID, FIRST_INFO);

    tests_run++;
    if (!operation_result && lifo_queue.count() == 0) {
        tests_passed++;
        std::cout << "PASS: LIFO rejected a negative id." << std::endl;
    } else {
        std::cout << "FAIL: LIFO accepted a negative id." << std::endl;
    }

    operation_result = lifo_queue.push(FIRST_ID, "");

    tests_run++;
    if (!operation_result && lifo_queue.count() == 0) {
        tests_passed++;
        std::cout << "PASS: LIFO rejected empty information." << std::endl;
    } else {
        std::cout << "FAIL: LIFO accepted empty information." << std::endl;
    }


    // =========================================================
    // PHASE 4: FIFO MULTI-NODE OPERATIONS
    // =========================================================
    std::cout << std::endl;
    std::cout << "--- PHASE 4: FIFO MULTI-NODE OPERATIONS ---"
              << std::endl;

    phase_success = true;

    if (!fifo_queue.push(FIRST_ID, FIRST_INFO)) {
        phase_success = false;
    }

    if (!fifo_queue.push(SECOND_ID, SECOND_INFO)) {
        phase_success = false;
    }

    if (!fifo_queue.push(THIRD_ID, THIRD_INFO)) {
        phase_success = false;
    }

    tests_run++;
    if (phase_success && fifo_queue.count() == THREE_ITEMS) {
        tests_passed++;
        std::cout << "PASS: FIFO accepted three valid items." << std::endl;
    } else {
        std::cout << "FAIL: FIFO did not accept three valid items."
                  << std::endl;
    }

    tests_run++;
    if (fifo_queue.peek() == FIRST_ID &&
        fifo_queue.count() == THREE_ITEMS) {
        tests_passed++;
        std::cout << "PASS: FIFO peek returns the oldest id without removal."
                  << std::endl;
    } else {
        std::cout << "FAIL: FIFO peek returned an incorrect id or changed count."
                  << std::endl;
    }

    tests_run++;
    if (fifo_queue.exists(FIRST_ID) &&
        fifo_queue.exists(SECOND_ID) &&
        fifo_queue.exists(THIRD_ID) &&
        !fifo_queue.exists(MISSING_ID) &&
        !fifo_queue.exists(INVALID_NEGATIVE_ID)) {
        tests_passed++;
        std::cout << "PASS: FIFO exists handles present and missing ids."
                  << std::endl;
    } else {
        std::cout << "FAIL: FIFO exists returned an incorrect result."
                  << std::endl;
    }

    /*
     * The challenge explicitly defines FIFO positions from the head.
     * Current physical order:
     * head -> 30 -> 20 -> 10 <- tail
     */
    tests_run++;
    if (fifo_queue.find(THIRD_ID) == 0 &&
        fifo_queue.find(SECOND_ID) == 1 &&
        fifo_queue.find(FIRST_ID) == TWO_ITEMS &&
        fifo_queue.find(MISSING_ID) == -1) {
        tests_passed++;
        std::cout << "PASS: FIFO find reports the required positions."
                  << std::endl;
    } else {
        std::cout << "FAIL: FIFO find reported incorrect positions."
                  << std::endl;
    }

    operation_result = fifo_queue.pull(returned_data);

    tests_run++;
    if (operation_result &&
        returned_data.id == FIRST_ID &&
        returned_data.information == FIRST_INFO &&
        fifo_queue.count() == TWO_ITEMS &&
        fifo_queue.peek() == SECOND_ID) {
        tests_passed++;
        std::cout << "PASS: FIFO first pull returned the oldest item."
                  << std::endl;
    } else {
        std::cout << "FAIL: FIFO first pull returned incorrect data."
                  << std::endl;
    }

    tests_run++;
    if (fifo_queue.find(THIRD_ID) == 0 &&
        fifo_queue.find(SECOND_ID) == 1 &&
        fifo_queue.find(FIRST_ID) == -1) {
        tests_passed++;
        std::cout << "PASS: FIFO find updated after a pull." << std::endl;
    } else {
        std::cout << "FAIL: FIFO find did not update after a pull."
                  << std::endl;
    }

    operation_result = fifo_queue.pull(returned_data);

    tests_run++;
    if (operation_result &&
        returned_data.id == SECOND_ID &&
        returned_data.information == SECOND_INFO &&
        fifo_queue.count() == 1 &&
        fifo_queue.peek() == THIRD_ID) {
        tests_passed++;
        std::cout << "PASS: FIFO second pull returned the next oldest item."
                  << std::endl;
    } else {
        std::cout << "FAIL: FIFO second pull returned incorrect data."
                  << std::endl;
    }

    operation_result = fifo_queue.pull(returned_data);

    tests_run++;
    if (operation_result &&
        returned_data.id == THIRD_ID &&
        returned_data.information == THIRD_INFO &&
        fifo_queue.count() == 0 &&
        fifo_queue.peek() == -1) {
        tests_passed++;
        std::cout << "PASS: FIFO final pull restored the empty state."
                  << std::endl;
    } else {
        std::cout << "FAIL: FIFO final pull did not restore the empty state."
                  << std::endl;
    }

    returned_data.id = FIRST_ID;
    returned_data.information = FIRST_INFO;
    operation_result = fifo_queue.pull(returned_data);

    tests_run++;
    if (!operation_result &&
        returned_data.id == -1 &&
        returned_data.information.empty()) {
        tests_passed++;
        std::cout << "PASS: FIFO underflow remains protected."
                  << std::endl;
    } else {
        std::cout << "FAIL: FIFO underflow was not protected."
                  << std::endl;
    }


    // =========================================================
    // PHASE 5: LIFO MULTI-NODE OPERATIONS
    // =========================================================
    std::cout << std::endl;
    std::cout << "--- PHASE 5: LIFO MULTI-NODE OPERATIONS ---"
              << std::endl;

    phase_success = true;

    if (!lifo_queue.push(FIRST_ID, FIRST_INFO)) {
        phase_success = false;
    }

    if (!lifo_queue.push(SECOND_ID, SECOND_INFO)) {
        phase_success = false;
    }

    if (!lifo_queue.push(THIRD_ID, THIRD_INFO)) {
        phase_success = false;
    }

    tests_run++;
    if (phase_success && lifo_queue.count() == THREE_ITEMS) {
        tests_passed++;
        std::cout << "PASS: LIFO accepted three valid items." << std::endl;
    } else {
        std::cout << "FAIL: LIFO did not accept three valid items."
                  << std::endl;
    }

    tests_run++;
    if (lifo_queue.peek() == THIRD_ID &&
        lifo_queue.count() == THREE_ITEMS) {
        tests_passed++;
        std::cout << "PASS: LIFO peek returns the newest id without removal."
                  << std::endl;
    } else {
        std::cout << "FAIL: LIFO peek returned an incorrect id or changed count."
                  << std::endl;
    }

    tests_run++;
    if (lifo_queue.exists(FIRST_ID) &&
        lifo_queue.exists(SECOND_ID) &&
        lifo_queue.exists(THIRD_ID) &&
        !lifo_queue.exists(MISSING_ID) &&
        !lifo_queue.exists(INVALID_NEGATIVE_ID)) {
        tests_passed++;
        std::cout << "PASS: LIFO exists handles present and missing ids."
                  << std::endl;
    } else {
        std::cout << "FAIL: LIFO exists returned an incorrect result."
                  << std::endl;
    }

    /*
     * The challenge explicitly defines LIFO positions from the tail.
     * Current physical order:
     * head -> 30 -> 20 -> 10 <- tail
     */
    tests_run++;
    if (lifo_queue.find(FIRST_ID) == 0 &&
        lifo_queue.find(SECOND_ID) == 1 &&
        lifo_queue.find(THIRD_ID) == TWO_ITEMS &&
        lifo_queue.find(MISSING_ID) == -1) {
        tests_passed++;
        std::cout << "PASS: LIFO find reports the required positions."
                  << std::endl;
    } else {
        std::cout << "FAIL: LIFO find reported incorrect positions."
                  << std::endl;
    }

    operation_result = lifo_queue.pull(returned_data);

    tests_run++;
    if (operation_result &&
        returned_data.id == THIRD_ID &&
        returned_data.information == THIRD_INFO &&
        lifo_queue.count() == TWO_ITEMS &&
        lifo_queue.peek() == SECOND_ID) {
        tests_passed++;
        std::cout << "PASS: LIFO first pull returned the newest item."
                  << std::endl;
    } else {
        std::cout << "FAIL: LIFO first pull returned incorrect data."
                  << std::endl;
    }

    tests_run++;
    if (lifo_queue.find(FIRST_ID) == 0 &&
        lifo_queue.find(SECOND_ID) == 1 &&
        lifo_queue.find(THIRD_ID) == -1) {
        tests_passed++;
        std::cout << "PASS: LIFO find updated after a pull." << std::endl;
    } else {
        std::cout << "FAIL: LIFO find did not update after a pull."
                  << std::endl;
    }

    operation_result = lifo_queue.pull(returned_data);

    tests_run++;
    if (operation_result &&
        returned_data.id == SECOND_ID &&
        returned_data.information == SECOND_INFO &&
        lifo_queue.count() == 1 &&
        lifo_queue.peek() == FIRST_ID) {
        tests_passed++;
        std::cout << "PASS: LIFO second pull returned the next newest item."
                  << std::endl;
    } else {
        std::cout << "FAIL: LIFO second pull returned incorrect data."
                  << std::endl;
    }

    operation_result = lifo_queue.pull(returned_data);

    tests_run++;
    if (operation_result &&
        returned_data.id == FIRST_ID &&
        returned_data.information == FIRST_INFO &&
        lifo_queue.count() == 0 &&
        lifo_queue.peek() == -1) {
        tests_passed++;
        std::cout << "PASS: LIFO final pull restored the empty state."
                  << std::endl;
    } else {
        std::cout << "FAIL: LIFO final pull did not restore the empty state."
                  << std::endl;
    }

    returned_data.id = FIRST_ID;
    returned_data.information = FIRST_INFO;
    operation_result = lifo_queue.pull(returned_data);

    tests_run++;
    if (!operation_result &&
        returned_data.id == -1 &&
        returned_data.information.empty()) {
        tests_passed++;
        std::cout << "PASS: LIFO underflow remains protected."
                  << std::endl;
    } else {
        std::cout << "FAIL: LIFO underflow was not protected."
                  << std::endl;
    }


    // =========================================================
    // PHASE 6: SINGLE-NODE BOUNDARY
    // =========================================================
    std::cout << std::endl;
    std::cout << "--- PHASE 6: SINGLE-NODE BOUNDARY ---" << std::endl;

    operation_result = fifo_queue.push(SINGLE_ID, SINGLE_INFO);

    tests_run++;
    if (operation_result &&
        fifo_queue.count() == 1 &&
        fifo_queue.peek() == SINGLE_ID &&
        fifo_queue.find(SINGLE_ID) == 0) {
        tests_passed++;
        std::cout << "PASS: FIFO single-node state is valid." << std::endl;
    } else {
        std::cout << "FAIL: FIFO single-node state is invalid." << std::endl;
    }

    operation_result = fifo_queue.pull(returned_data);

    tests_run++;
    if (operation_result &&
        returned_data.id == SINGLE_ID &&
        returned_data.information == SINGLE_INFO &&
        fifo_queue.count() == 0 &&
        fifo_queue.peek() == -1) {
        tests_passed++;
        std::cout << "PASS: FIFO safely removed its only node."
                  << std::endl;
    } else {
        std::cout << "FAIL: FIFO did not safely remove its only node."
                  << std::endl;
    }

    operation_result = lifo_queue.push(SINGLE_ID, SINGLE_INFO);

    tests_run++;
    if (operation_result &&
        lifo_queue.count() == 1 &&
        lifo_queue.peek() == SINGLE_ID &&
        lifo_queue.find(SINGLE_ID) == 0) {
        tests_passed++;
        std::cout << "PASS: LIFO single-node state is valid." << std::endl;
    } else {
        std::cout << "FAIL: LIFO single-node state is invalid." << std::endl;
    }

    operation_result = lifo_queue.pull(returned_data);

    tests_run++;
    if (operation_result &&
        returned_data.id == SINGLE_ID &&
        returned_data.information == SINGLE_INFO &&
        lifo_queue.count() == 0 &&
        lifo_queue.peek() == -1) {
        tests_passed++;
        std::cout << "PASS: LIFO safely removed its only node."
                  << std::endl;
    } else {
        std::cout << "FAIL: LIFO did not safely remove its only node."
                  << std::endl;
    }


    // =========================================================
    // PHASE 7: DUPLICATE IDS
    // =========================================================
    std::cout << std::endl;
    std::cout << "--- PHASE 7: DUPLICATE IDS ---" << std::endl;

    phase_success = true;

    if (!fifo_queue.push(DUPLICATE_ID, DUPLICATE_FIRST_INFO)) {
        phase_success = false;
    }

    if (!fifo_queue.push(DUPLICATE_ID, DUPLICATE_SECOND_INFO)) {
        phase_success = false;
    }

    tests_run++;
    if (phase_success &&
        fifo_queue.count() == TWO_ITEMS &&
        fifo_queue.exists(DUPLICATE_ID) &&
        fifo_queue.find(DUPLICATE_ID) == 0) {
        tests_passed++;
        std::cout << "PASS: FIFO accepts and locates duplicate ids."
                  << std::endl;
    } else {
        std::cout << "FAIL: FIFO duplicate-id behavior is incorrect."
                  << std::endl;
    }

    phase_success = true;
    operation_result = fifo_queue.pull(returned_data);

    if (!operation_result ||
        returned_data.id != DUPLICATE_ID ||
        returned_data.information != DUPLICATE_FIRST_INFO) {
        phase_success = false;
    }

    operation_result = fifo_queue.pull(returned_data);

    if (!operation_result ||
        returned_data.id != DUPLICATE_ID ||
        returned_data.information != DUPLICATE_SECOND_INFO) {
        phase_success = false;
    }

    tests_run++;
    if (phase_success && fifo_queue.count() == 0) {
        tests_passed++;
        std::cout << "PASS: FIFO preserves insertion order for duplicate ids."
                  << std::endl;
    } else {
        std::cout << "FAIL: FIFO duplicate items were returned incorrectly."
                  << std::endl;
    }

    phase_success = true;

    if (!lifo_queue.push(DUPLICATE_ID, DUPLICATE_FIRST_INFO)) {
        phase_success = false;
    }

    if (!lifo_queue.push(DUPLICATE_ID, DUPLICATE_SECOND_INFO)) {
        phase_success = false;
    }

    tests_run++;
    if (phase_success &&
        lifo_queue.count() == TWO_ITEMS &&
        lifo_queue.exists(DUPLICATE_ID) &&
        lifo_queue.find(DUPLICATE_ID) == 0) {
        tests_passed++;
        std::cout << "PASS: LIFO accepts and locates duplicate ids."
                  << std::endl;
    } else {
        std::cout << "FAIL: LIFO duplicate-id behavior is incorrect."
                  << std::endl;
    }

    phase_success = true;
    operation_result = lifo_queue.pull(returned_data);

    if (!operation_result ||
        returned_data.id != DUPLICATE_ID ||
        returned_data.information != DUPLICATE_SECOND_INFO) {
        phase_success = false;
    }

    operation_result = lifo_queue.pull(returned_data);

    if (!operation_result ||
        returned_data.id != DUPLICATE_ID ||
        returned_data.information != DUPLICATE_FIRST_INFO) {
        phase_success = false;
    }

    tests_run++;
    if (phase_success && lifo_queue.count() == 0) {
        tests_passed++;
        std::cout << "PASS: LIFO preserves reverse insertion order for duplicates."
                  << std::endl;
    } else {
        std::cout << "FAIL: LIFO duplicate items were returned incorrectly."
                  << std::endl;
    }


    // =========================================================
    // PHASE 8: CLEAR AND REUSE
    // =========================================================
    std::cout << std::endl;
    std::cout << "--- PHASE 8: CLEAR AND REUSE ---" << std::endl;

    fifo_queue.push(FIRST_ID, FIRST_INFO);
    fifo_queue.push(SECOND_ID, SECOND_INFO);
    fifo_queue.push(THIRD_ID, THIRD_INFO);
    fifo_queue.clear();

    tests_run++;
    if (fifo_queue.count() == 0 &&
        fifo_queue.peek() == -1 &&
        !fifo_queue.exists(FIRST_ID) &&
        fifo_queue.find(FIRST_ID) == -1) {
        tests_passed++;
        std::cout << "PASS: FIFO clear removed all nodes." << std::endl;
    } else {
        std::cout << "FAIL: FIFO clear left residual state." << std::endl;
    }

    operation_result = fifo_queue.push(REUSE_ID, REUSE_INFO);

    tests_run++;
    if (operation_result &&
        fifo_queue.count() == 1 &&
        fifo_queue.peek() == REUSE_ID) {
        tests_passed++;
        std::cout << "PASS: FIFO can be reused after clear." << std::endl;
    } else {
        std::cout << "FAIL: FIFO could not be reused after clear."
                  << std::endl;
    }

    operation_result = fifo_queue.pull(returned_data);

    tests_run++;
    if (operation_result &&
        returned_data.id == REUSE_ID &&
        returned_data.information == REUSE_INFO &&
        fifo_queue.count() == 0) {
        tests_passed++;
        std::cout << "PASS: Reused FIFO returned correct data." << std::endl;
    } else {
        std::cout << "FAIL: Reused FIFO returned incorrect data."
                  << std::endl;
    }

    lifo_queue.push(FIRST_ID, FIRST_INFO);
    lifo_queue.push(SECOND_ID, SECOND_INFO);
    lifo_queue.push(THIRD_ID, THIRD_INFO);
    lifo_queue.clear();

    tests_run++;
    if (lifo_queue.count() == 0 &&
        lifo_queue.peek() == -1 &&
        !lifo_queue.exists(FIRST_ID) &&
        lifo_queue.find(FIRST_ID) == -1) {
        tests_passed++;
        std::cout << "PASS: LIFO clear removed all nodes." << std::endl;
    } else {
        std::cout << "FAIL: LIFO clear left residual state." << std::endl;
    }

    operation_result = lifo_queue.push(REUSE_ID, REUSE_INFO);

    tests_run++;
    if (operation_result &&
        lifo_queue.count() == 1 &&
        lifo_queue.peek() == REUSE_ID) {
        tests_passed++;
        std::cout << "PASS: LIFO can be reused after clear." << std::endl;
    } else {
        std::cout << "FAIL: LIFO could not be reused after clear."
                  << std::endl;
    }

    operation_result = lifo_queue.pull(returned_data);

    tests_run++;
    if (operation_result &&
        returned_data.id == REUSE_ID &&
        returned_data.information == REUSE_INFO &&
        lifo_queue.count() == 0) {
        tests_passed++;
        std::cout << "PASS: Reused LIFO returned correct data." << std::endl;
    } else {
        std::cout << "FAIL: Reused LIFO returned incorrect data."
                  << std::endl;
    }


    // =========================================================
    // PHASE 9: HIGH-VOLUME STRESS TEST
    // =========================================================
    std::cout << std::endl;
    std::cout << "--- PHASE 9: HIGH-VOLUME STRESS TEST ---"
              << std::endl;

    phase_success = true;

    for (int i = 0; i < STRESS_COUNT; i++) {
        expected_id = STRESS_BASE_ID + i;
        expected_information = STRESS_PREFIX + std::to_string(expected_id);

        if (!fifo_stress.push(expected_id, expected_information)) {
            phase_success = false;
        }

        if (!lifo_stress.push(expected_id, expected_information)) {
            phase_success = false;
        }
    }

    tests_run++;
    if (phase_success &&
        fifo_stress.count() == STRESS_COUNT &&
        lifo_stress.count() == STRESS_COUNT) {
        tests_passed++;
        std::cout << "PASS: Both queues accepted "
                  << STRESS_COUNT
                  << " dynamically allocated nodes."
                  << std::endl;
    } else {
        std::cout << "FAIL: High-volume push testing failed."
                  << std::endl;
    }

    tests_run++;
    if (fifo_stress.peek() == STRESS_BASE_ID &&
        lifo_stress.peek() == STRESS_BASE_ID + STRESS_COUNT - 1) {
        tests_passed++;
        std::cout << "PASS: Stress-test peeks reflect FIFO and LIFO order."
                  << std::endl;
    } else {
        std::cout << "FAIL: Stress-test peeks returned incorrect ids."
                  << std::endl;
    }

    tests_run++;
    if (fifo_stress.find(STRESS_BASE_ID + STRESS_COUNT - 1) == 0 &&
        fifo_stress.find(STRESS_BASE_ID) == STRESS_COUNT - 1 &&
        lifo_stress.find(STRESS_BASE_ID) == 0 &&
        lifo_stress.find(STRESS_BASE_ID + STRESS_COUNT - 1) ==
            STRESS_COUNT - 1) {
        tests_passed++;
        std::cout << "PASS: Stress-test find positions are correct."
                  << std::endl;
    } else {
        std::cout << "FAIL: Stress-test find positions are incorrect."
                  << std::endl;
    }

    phase_success = true;

    for (int i = 0; i < STRESS_COUNT; i++) {
        expected_id = STRESS_BASE_ID + i;
        expected_information = STRESS_PREFIX + std::to_string(expected_id);
        operation_result = fifo_stress.pull(returned_data);

        if (!operation_result ||
            returned_data.id != expected_id ||
            returned_data.information != expected_information) {
            phase_success = false;
        }

        expected_id = STRESS_BASE_ID + STRESS_COUNT - 1 - i;
        expected_information = STRESS_PREFIX + std::to_string(expected_id);
        operation_result = lifo_stress.pull(returned_data);

        if (!operation_result ||
            returned_data.id != expected_id ||
            returned_data.information != expected_information) {
            phase_success = false;
        }
    }

    tests_run++;
    if (phase_success &&
        fifo_stress.count() == 0 &&
        lifo_stress.count() == 0 &&
        fifo_stress.peek() == -1 &&
        lifo_stress.peek() == -1) {
        tests_passed++;
        std::cout << "PASS: Both queues survived ordered high-volume removal."
                  << std::endl;
    } else {
        std::cout << "FAIL: High-volume removal testing failed."
                  << std::endl;
    }


    // =========================================================
    // FINAL REPORT
    // =========================================================
    std::cout << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << "              FINAL REPORT                " << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << "Tests Run:    " << tests_run << std::endl;
    std::cout << "Tests Passed: " << tests_passed << std::endl;
    std::cout << "Tests Failed: " << tests_run - tests_passed << std::endl;

    if (tests_passed == tests_run) {
        std::cout << "RESULT: ALL QUEUE TESTS PASSED." << std::endl;
    } else {
        std::cout << "RESULT: ONE OR MORE QUEUE TESTS FAILED."
                  << std::endl;
    }

    return 0;
}