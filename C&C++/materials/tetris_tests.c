#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../brick_game/tetris/tetris.h"

START_TEST(test_copyTetrino) {
  Tetrino_t tetr_1, tetr_2;
  GreatFlag_t check = SUCCESS;
  ck_assert_int_eq(shapeAllocationMaster(&tetr_1), check);
  ck_assert_int_eq(shapeAllocationMaster(&tetr_2), check);
  tetr_1.type = tt_LeftL;
  tetr_1.x = WIDTH / 2;
  tetr_1.y = HEIGHT / 2 + 5;
  for (int i = 0; i < PIECE_SIZE; i++) {
    for (int j = 0; j < PIECE_SIZE; j++) {
      tetr_1.shape[i][j] = (i + j) % 2;
    }
  }
  copyTetrino(&tetr_1, &tetr_2);
  ck_assert_int_eq(tetr_1.type, tetr_2.type);
  ck_assert_int_eq(tetr_1.x, tetr_2.x);
  ck_assert_int_eq(tetr_1.y, tetr_2.y);
  for (int i = 0; i < PIECE_SIZE; i++) {
    for (int j = 0; j < PIECE_SIZE; j++) {
      ck_assert_int_eq(tetr_1.shape[i][j], tetr_2.shape[i][j]);
    }
  }
  shapeFreeMaster(&tetr_1, PIECE_SIZE);
  shapeFreeMaster(&tetr_2, PIECE_SIZE);
}
START_TEST(test_cleanTetrino) {
  GameMain_t core;
  GreatFlag_t check = SUCCESS;
  ck_assert_int_eq(shapeAllocationMaster(&(core.piece)), check);
  core.piece.type = tt_LeftSnake;
  core.piece.x = WIDTH - 4;
  core.piece.y = HEIGHT - 4;
  for (int i = 0; i < PIECE_SIZE; i++) {
    for (int j = 0; j < PIECE_SIZE; j++) {
      core.piece.shape[i][j] = (i + j) % 2;
    }
  }
  ck_assert_int_eq(core.piece.type, tt_LeftSnake);
  ck_assert_int_eq(core.piece.x, WIDTH - 4);
  ck_assert_int_eq(core.piece.y, HEIGHT - 4);
  for (int i = 0; i < PIECE_SIZE; i++) {
    for (int j = 0; j < PIECE_SIZE; j++) {
      ck_assert_int_eq(core.piece.shape[i][j], (i + j) % 2);
    }
  }
  cleanTetrino(&(core.piece));
  ck_assert_int_eq(core.piece.type, tt_None);
  ck_assert_int_eq(core.piece.x, 0);
  ck_assert_int_eq(core.piece.y, 0);
  for (int i = 0; i < PIECE_SIZE; i++) {
    for (int j = 0; j < PIECE_SIZE; j++) {
      ck_assert_int_eq(core.piece.shape[i][j], 0);
    }
  }
  shapeFreeMaster(&(core.piece), PIECE_SIZE);
}
START_TEST(test_setShape) {
  GameMain_t core;
  const int arr[PIECE_SIZE * PIECE_SIZE] = INIT_LINE;
  GreatFlag_t check = SUCCESS;
  ck_assert_int_eq(shapeAllocationMaster(&(core.piece)), check);
  core.piece.type = tt_Line;
  core.piece.x = WIDTH / 2;
  core.piece.y = 5;
  for (int i = 0; i < PIECE_SIZE; i++) {
    for (int j = 0; j < PIECE_SIZE; j++) {
      core.piece.shape[i][j] = TAKEN;
    }
  }
  setShape(arr, &(core.piece.shape));
  ck_assert_int_eq(core.piece.type, tt_Line);
  ck_assert_int_eq(core.piece.x, WIDTH / 2);
  ck_assert_int_eq(core.piece.y, 5);
  for (int i = 0; i < PIECE_SIZE; i++) {
    for (int j = 0; j < PIECE_SIZE; j++) {
      if (i == 1)
        ck_assert_int_eq(core.piece.shape[i][j], TAKEN);
      else
        ck_assert_int_eq(core.piece.shape[i][j], EMPTY);
    }
  }
  shapeFreeMaster(&(core.piece), PIECE_SIZE);
}

START_TEST(test_timer) {
  int time_O;
  int sec, check = 1;
  startTimer();
  time_O = clock();
  while (1) {
    sec = (clock() - time_O) / CLOCKS_PER_SEC;
    if (sec == check) {
      check++;
      ck_assert_int_eq(getTimer(), sec);
    }
    if (check == 3) break;
  }
  startTimer();
  time_O = clock();
  check = 1;
  while (1) {
    sec = (clock() - time_O) / CLOCKS_PER_SEC;
    if (sec == check) {
      check++;
      ck_assert_int_eq(getTimer(), sec);
    }
    if (check == 2) break;
  }

  startTimer();
  time_O = clock();
  check = 5;
  int save = 2;
  int flag = 0;
  while (1) {
    sec = (clock() - time_O) / CLOCKS_PER_SEC;
    if (sec == save && flag == 0) {
      ck_assert_int_eq(getTimer(), sec);
      pauseTimer();
      flag++;
    }

    if (sec == check && flag == 1) {
      ck_assert_int_eq(sec, check);
      ck_assert_int_eq(getTimer(), save);
      pauseTimer();
      flag++;
      time_O = clock() - CLOCKS_PER_SEC * check;
    }
    if (flag == 2 && sec == check + save) {
      ck_assert_int_eq(sec, check + save);
      ck_assert_int_eq(getTimer(), save * 2);
      break;
    }
  }
}
START_TEST(test_strokesToMake) {
  int time_O;
  int level = 1;
  int check = 2;
  startTimer();
  time_O = clock();
  int i = 0;
  while (1) {
    if ((clock() - time_O) / CLOCKS_PER_SEC == 4) {
      time_O = clock();
      ck_assert_int_eq(strokesToMake(level), check);
      level++;
      switch (level) {
        case 2:
          check = 4;
          break;
        case 3:
          check = 5;
          break;
        case 5:
          check = 6;
          break;
        case 6:
          check = 8;
          break;
        case 7:
          check = 10;
          break;
        case 8:
          check = 16;
          break;
        case 9:
          check = 20;
          break;
        case 10:
          check = 40;
          break;
        default:
          break;
      }
    }
    if (level == 5 && (i == 0 || i == 10)) {
      pauseTimer();
      i++;
      time_O = clock();
    }
    if (level == 5) {
      i++;
    }

    if (level == 11)  // 12 - for best full check
      break;
  }
}

START_TEST(test_catchUpStructure) {
  GameMain_t *core = structureKeeper();
  userInput(Start, 1);
  clock_t time_0 = clock();
  int move_for = 10;
  while (1) {
    if ((clock() - time_0) / (CLOCKS_PER_SEC * move_for) >= 1) {
      catchUpStructure();
      break;
    }
  }
  ck_assert_int_eq(core->piece.y, move_for / levelTable(1));
  userInput(Terminate, 1);
}

START_TEST(test_whenScoreChanges) {
  userInput(Start, 1);
  GameMain_t *core = structureKeeper();
  whenScoreChanges();
  core->score = MAX_SCORE;
  whenScoreChanges();
  ck_assert_int_eq(core->score, MAX_SCORE);
  ck_assert_int_eq(core->high_score, MAX_SCORE);
  userInput(Terminate, 1);
  userInput(Terminate, 1);
}

void test_block_1(SRunner *sr) {
  Suite *s = suite_create("Test block #1");
  TCase *tc_core = tcase_create("Core");
  suite_add_tcase(s, tc_core);

  tcase_add_test(tc_core, test_copyTetrino);
  tcase_add_test(tc_core, test_cleanTetrino);
  tcase_add_test(tc_core, test_setShape);

  srunner_add_suite(sr, s);
}
void test_block_2(SRunner *sr) {
  Suite *s = suite_create(
      "Test block #2: timer related \n (testing may take a while...)");
  TCase *tc_core = tcase_create("Core");
  suite_add_tcase(s, tc_core);

  tcase_add_test(tc_core, test_timer);
  tcase_add_test(tc_core, test_strokesToMake);
  tcase_add_test(tc_core, test_catchUpStructure);

  srunner_add_suite(sr, s);
}
void test_block_3(SRunner *sr) {
  Suite *s = suite_create("Test block #3: extra tests");
  TCase *tc_core = tcase_create("Core");
  suite_add_tcase(s, tc_core);

  tcase_add_test(tc_core, test_whenScoreChanges);

  srunner_add_suite(sr, s);
}

int main(void) {
  int number_failed;
  Suite *s = suite_create("Tetris tests");
  SRunner *sr = srunner_create(s);

  test_block_1(sr);
  test_block_2(sr);
  test_block_3(sr);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
