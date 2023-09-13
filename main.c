/*Mathew Mani
UIN: 673274206
NetId:mmani7@uic.edu
CS 211, Kidane 
Program 3: TwentyFour Part Two*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Node struct for a character type stack
struct Node {
  char data;
  struct Node *next;
};

// stack struct for a character type stack
struct stack {
  struct Node *top;
};

// Node struct for an int ype stack
struct numNode {
  int data;
  struct numNode *next;
};

//Stack struct for a int type stack
struct numstack {
  struct numNode *top;
};

//default constructor for a character node
struct Node *newNode(char data) {
  struct Node *adder = (struct Node *)malloc(sizeof(struct Node));
  adder->data = data;
  adder->next = NULL;
  return adder;
}

//default constructor for an integer node
struct numNode *intnewNode(int data) {
  struct numNode *adder = (struct numNode *)malloc(sizeof(struct numNode));
  adder->data = data;
  adder->next = NULL;
  return adder;
}

//pushes a new node into the character stack
void push(struct stack *Stack, char number) {
  struct Node *element = newNode(number);
  element->next = Stack->top;
  Stack->top = element;
}

//pops a node from a character stack
char pop(struct stack *Stack) {
  char x = Stack->top->data;
  struct Node *temp = Stack->top;
  Stack->top = temp->next;
  free(temp);
  return x;
}

//pushes a new node into the integer stack
void intpush(struct numstack *Stack, int number) {
  struct numNode *element = intnewNode(number);
  element->next = Stack->top;
  Stack->top = element;
}

//pops a node from an integer stack
int intpop(struct numstack *Stack) {
  int x = Stack->top->data;
  struct numNode *temp = Stack->top;
  Stack->top = temp->next;
  free(temp);
  return x;
}

//returns 1 if character stack is empty
int emptystack(struct stack *Stack) {
  if (Stack->top == NULL) {
    return 1;
  } else {
    return 0;
  }
}

//returns size of character stack
int stacksize(struct stack *Stack) {
  if (Stack->top == NULL) {
    return 0;
  }
  struct Node *temp = Stack->top;
  int x = 0;
  while (temp != NULL) {
    temp = temp->next;
    x++;
  }
  return x;
}

//returns size of integer stack
int intstacksize(struct numstack *intstack) {
  if (intstack->top == NULL) {
    return 0;
  }
  struct numNode *temp = intstack->top;
  int x = 0;
  while (temp != NULL) {
    temp = temp->next;
    x++;
  }
  return x;
}

//displays character stack for testing purposes
void displaystack(struct stack *Stack) {
  struct Node *temp = Stack->top;
  while (temp != NULL) {
    printf("%c, ", temp->data);
    temp = temp->next;
  }
  printf(".\n");
}

//displays integer stack for testing purposes
void intdisplaystack(struct numstack *Stack) {
  struct numNode *temp = Stack->top;
  while (temp != NULL) {
    printf("%d, ", temp->data);
    temp = temp->next;
  }
  printf(".\n");
}

//returns 1 if a given element exists in the character stack
int exists(struct stack *Stack, char number) {
  if (Stack->top == NULL) {
    return 0;
  }
  struct Node *temp = Stack->top;
  while (temp != NULL) {
    if (temp->data == number) {
      return 1;
    } else {
      temp = temp->next;
    }
  }
  return 0;
}

//empties a character stack
void emptythestack(struct stack *Stack) {
  if (Stack->top == NULL) {
    return;
  }
  while (Stack->top != NULL) {
    pop(Stack);
  }
}

//empties an integer stack
void intemptythestack(struct numstack *Stack) {
  if (Stack->top == NULL) {
    return;
  }
  while (Stack->top != NULL) {
    intpop(Stack);
  }
}

//given a character, it returns how many times that character appears in a stack
int howmany(struct stack *Stack, char a) {
  int x = 0;
  struct Node *temp = Stack->top;
  while (temp != NULL) {
    if (temp->data == a) {
      x++;
      temp = temp->next;
    } else {
      temp = temp->next;
    }
  }
  return x;
}

//returns a reversed stack from the input
struct stack* reversestack(struct stack *s) {
    struct Node *prev = NULL;
    struct Node *current = s->top;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    s->top = prev;
  return s;
}

//returns a reversed integer stack from the input
struct numstack *intreversestack(struct numstack *s) {
  struct numNode *prev = NULL;
    struct numNode *current = s->top;
    struct numNode *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    s->top = prev;
  return s;
}

//given two numbers and an operator, it returns the answer to the expression
int expressions(int a, int b, char c) {
  if (c == '+') {
    return a + b;
  } else if (c == '-') {
    return a - b;
  } else if (c == '*') {
    return a * b;
  } else {
    return a / b;
  }
}

//Used to see if there are too many values in the expression. The integer stack should be one more than the operator stack
int theymatch(struct stack *chars, struct numstack *ints) {
  if (intstacksize(ints) - stacksize(chars) == 1) {
    return 1;
  } else if (intstacksize(ints) == 0 && stacksize(chars) == 0) {
    return 1;
  }

  else {
    return 0;
  }
}

//obtained from stack overflow to help read in newlines. Did not use in the end but used for testing purposes
void clearBuffer(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  // printf("end of while loop");
}

//displays the menu and returns a number based on what was inputted
int menu() {
  printf("Enter:  1 to play again,\n");
  printf("        2 to change the difficulty level and then play again, or\n");
  printf("        3 to exit the program.\n");
  printf("Your choice --> ");
  char option2;
  scanf(" %c", &option2);
  // clear_buffer();
  if (option2 == '1') {
    return 1;
  } else if (option2 == '2') {
    return 2;
  } else if (option2 == '3') {
    return 3;
  }
}

//displays beggining part of the game
void beggining() {
  printf("Welcome to the game of TwentyFour Part Two!\n");
  printf("Use each of the four numbers shown exactly once, \n");
  printf("combining them somehow with the basic mathematical operators "
         "(+,-,*,/) \n");
  printf("to yield the value twenty-four.\n");
}

//if E or another character is chosen, this obtains a random puzzle from the file
char *easyrandom() {
  char array[12][4];
  char largearray[48];
  char filename[] = "easy.txt";
  FILE *filePtr = fopen(filename, "r");
  char num;
  if (filePtr == NULL) {
    printf("Error: could not open %s for reading\n", filename);
    exit(-1);
  }
  int index = 0;
  int space = 0;
  while (fscanf(filePtr, "%c ", &num) != EOF) {
    if (num == ' ') {
      continue;
    } else {
      largearray[index] = num;
      index++;
    }
  }
  fclose(filePtr);
  int i;
  int j;
  int inde = 0;
  //gives a 2d array of line number and array of puzzles
  for (i = 0; i < 12; i++) {
    for (j = 0; j < 4; j++) {
      array[i][j] = largearray[inde];  
      inde++;
    }
  }
  int randomnumber = rand() % 12;
  char *puzzle = malloc(sizeof(char) * 5);
  //allocates space for puzzle
  int k;
  for (k = 0; k < 4; k++) {
    puzzle[k] = array[randomnumber][k];
  }
  puzzle[4] = '\0';
  return puzzle;
}

//if M  is chosen, this obtains a random puzzle from the file. Uses same logic as easyrandom()
char *mediumrandom() {
  char array[24][4];
  char largearray[96];
  char filename[] = "medium.txt";
  FILE *filePtr = fopen(filename, "r");
  char num;
  if (filePtr == NULL) {
    printf("Error: could not open %s for reading\n", filename);
    exit(-1);
  }
  int index = 0;
  int space = 0;
  while (fscanf(filePtr, "%c ", &num) != EOF) {
    largearray[index] = num;
    index++;
  }
  fclose(filePtr);
  int i;
  int j;
  int inde = 0;
  for (i = 0; i < 24; i++) {
    for (j = 0; j < 4; j++) {
      array[i][j] = largearray[inde];
      inde++;
    }
  }
  int randomnumber = rand() % 24;
  char *puzzle = malloc(sizeof(char) * 5);
  int k;
  for (k = 0; k < 4; k++) {
    puzzle[k] = array[randomnumber][k];
  }
  puzzle[4] = '\0';
  return puzzle;
}

//if H  is chosen, this obtains a random puzzle from the file. Uses same logic as easyrandom()
char *hardrandom() {
  char array[11][4];
  char largearray[44];
  char filename[] = "hard.txt";
  FILE *filePtr = fopen(filename, "r");
  char num;
  if (filePtr == NULL) {
    printf("Error: could not open %s for reading\n", filename);
    exit(-1);
  }
  int index = 0;
  int space = 0;
  while (fscanf(filePtr, "%c ", &num) != EOF) {
    largearray[index] = num;
    index++;
  }
  fclose(filePtr);
  int i;
  int j;
  int inde = 0;
  for (i = 0; i < 11; i++) {
    for (j = 0; j < 4; j++) {
      array[i][j] = largearray[inde];
      inde++;
    }
  }
  int randomnumber = rand() % 11;
  char *puzzle = malloc(sizeof(char) * 5);
  int k;
  for (k = 0; k < 4; k++) {
    puzzle[k] = array[randomnumber][k];
  }
  puzzle[4] = '\0';
  return puzzle;
}

//sees if input expression does not have invalid special characters
int checkvalidity(char answer[81]) {
  int i = 0;
  while (answer[i] != '\0') {
    if (isdigit(answer[i])) {
      i++;
      continue;
    } else if (answer[i] == ' ' || answer[i] == '+' || answer[i] == '-' ||
               answer[i] == '*' || answer[i] == '/' || answer[i] == '(' ||
               answer[i] == ')' || answer[i] == '\n') {
      i++;
      continue;
    } else {
      return 0;
    }
  }
  return 1;
}

//checks to see if all numbers in puzzle are in the user expression. I utilize two stacks and the exists() function
int allnumbersexist(char *puzzle, struct stack *Stack) {
  struct stack *newstack = (struct stack *)malloc(sizeof(struct stack));
  newstack->top = NULL;
  int i = 0;
  while (puzzle[i] != '\0') {
    if (isdigit(puzzle[i])) {
      push(newstack, (puzzle[i]));
      i++;
    } else {
      i++;
    }
  }
  struct Node *temp = Stack->top;
  while (temp != NULL) {
    //do not need to check if values are equal. If one value is present as many times in one stack as another, it is valid
    if (howmany(newstack, temp->data) == howmany(Stack, temp->data)) { 
      temp = temp->next;
    } else {
      emptythestack(newstack);
      free(newstack);
      return 0;
    }
  }
  //empties and frees the new stack
  emptythestack(newstack);
  free(newstack);
  return 1;
}

//takes in an integer stack and an operator stack then calculates and displays expression
void twostacks(struct numstack *intstack, struct stack *charstack) {
  if (intstacksize(intstack) < 2 || stacksize(charstack) == 0) {
    return;
  }
  int num; //future answer to expression
  while (emptystack(charstack) == 0) {
    char oper = pop(charstack);
    int x = intpop(intstack);  //x is the popped stack because stacks are reversed beforehand
    int y = intpop(intstack);
    num = expressions(x, y, oper);
    printf("%d%c%d = %d.\n", x, oper, y, num);
    intpush(intstack, num);
  }
}

/*does the same as twostacks but is specified for characters and integers in parentheses
in some cases, we need to push num onto the integer stack and others not, so we use int x
as a deciding parameter*/
void doublestacks(struct numstack *intstack, struct numstack *parintstack,
                  struct stack *parcharstack, int x) {
  if (intstacksize(parintstack) < 2 || stacksize(parcharstack) == 0) {
    return;
  }
  int num;
  while (emptystack(parcharstack) == 0) {
    char oper = pop(parcharstack);
    int x = intpop(parintstack);
    int y = intpop(parintstack);
    num = expressions(x, y, oper);
    printf("%d%c%d = %d.\n", x, oper, y, num);
    intpush(parintstack, num);  //needs to be pushed on parentheses integer stack at all times
  }
  if (x == 1) {
    intpush(intstack, parintstack->top->data);
  } else {
    return;
  }
}

/*function dedicated to test cases where too many closing parentheses are there. 
Performs calculation without looking at parentheses first*/
void closing(char only[81], struct stack *charstack, struct numstack *intstack,
             struct stack *parcharstack, struct numstack *parintstack) {
  char oper;
  int x;
  int y;
  int num;

  int stacknumber = 0;
  int counterpart = 0;
  int i = 0;
  while (only[i] != '\0') {     //Same while loop as regular while loop in playgame with little differences
    if(counterpart>stacknumber){
      twostacks(intstack,charstack);
      break;
    }
    if (only[i] == '(') {
      stacknumber++;
      i++;
      while (stacknumber != counterpart) {
        if (only[i] == '(') {
          stacknumber++;
          i++;
          continue;
        } else if (only[i] == ')') {
          counterpart++;
          if (counterpart == stacknumber) {
            if(intstacksize(parintstack) == 1){
              intpush(intstack,parintstack->top->data);
            }
            i++;
            break;
          }
          if (intstacksize(parintstack) == 1) {
            if (only[i + 1] == '\0') {
              intpush(intstack, parintstack->top->data);
              intemptythestack(parintstack);
              break;
            } else {
              i++;
              break;
            }
          } else {
            parintstack = intreversestack(parintstack);
            parcharstack = reversestack(parcharstack);
            doublestacks(intstack, parintstack, parcharstack, 0);
            i++;
            continue;
          }
        }
        if (isdigit(only[i])) {
          intpush(parintstack, (only[i] - '0'));
          i++;
          continue;
        } else {
          if (only[i] == '*' || only[i] == '/') {
            push(parcharstack, only[i]);
            if (only[i + 1] == '(') {
              oper = pop(charstack);
              push(charstack, oper);
              intpush(intstack, parintstack->top->data);
              intemptythestack(parintstack);
              i++;
              continue;
            }
            oper = pop(parcharstack);
            intpush(parintstack, (only[i + 1]) - '0');
            i++;
            x = intpop(parintstack);
            y = intpop(parintstack);
            num = expressions(y, x, oper);
            printf("%d%c%d = %d.\n", y, oper, x, num);
            intpush(parintstack, num);
            i++;
          } else {
            push(parcharstack, only[i]);
            i++;
          }
        }
      }
      if (intstacksize(parintstack) == 1) {
        intpush(intstack, parintstack->top->data);
        emptythestack(parcharstack);
        intemptythestack(parintstack);
        continue;
      } else {
        parintstack = intreversestack(parintstack);
        parcharstack = reversestack(parcharstack);
        doublestacks(intstack, parintstack, parcharstack, 1);
        emptythestack(parcharstack);
        intemptythestack(parintstack);
        if (only[i + 1] == '\0') {
          break;
        }
        if (only[i] == '\0') {
          break;
        }
        continue;
      }

    } else if (only[i] == ')') {
      counterpart++;
      if (only[i + 1] == '(') {
        printf("Error! Too many values in the expression.\n");
        
        return;
      } else {
        i++;
        continue;
      }
    } else if (only[i] == '\n' || only[i] == ' ' || only[i] == '0') {
      i++;
      continue;
    } else {
      if (isdigit(only[i])) {
        intpush(intstack, only[i] - '0');
        i++;
      } else {
        if (only[i] == '*' || only[i] == '/' || only[i] == '+' ||
            only[i] == '-') {  //main differecnce between other while loop. All equations are done right away
          push(charstack, only[i]);
          if (only[i + 1] == '(') {
            i++;
            continue;
          }
          oper = pop(charstack);
          intpush(intstack, (only[i + 1]) - '0');
          i++;
          x = intpop(intstack);
          y = intpop(intstack);
          num = expressions(y, x, oper);
          printf("%d%c%d = %d.\n", y, oper, x, num);
          intpush(intstack, num);
          i++;
        }
      }
    }
  }
//need to reverse stacks to maintain order of expressions as well as displaying them
intstack = intreversestack(intstack);
charstack = reversestack(charstack);  

  twostacks(intstack,charstack);
  printf("Error! Too many closing parentheses in the expression.\n\n");
  return;
}

/*main bulk of program. Utilizes all above functions except for purely display ones.
checks if user entry is valid and then performs calculations*/
void playgame(char *puzzle, char option) {
    int valid = 0;
    char answer[81];
    char only[81];
    //initialization of all stacks used in the program
    struct stack *charstack = (struct stack *)malloc(sizeof(struct stack));
    struct numstack *intstack =
        (struct numstack *)malloc(sizeof(struct numstack));
    struct stack *parcharstack = (struct stack *)malloc(sizeof(struct stack));
    struct numstack *parintstack =
        (struct numstack *)malloc(sizeof(struct numstack));
    struct stack *fakestack = (struct stack *)malloc(sizeof(struct stack));
    fakestack->top = NULL;
    charstack->top = NULL;
    intstack->top = NULL;
    parcharstack->top = NULL;
    parintstack->top = NULL;
  while (valid == 0) {
    printf("The numbers to use are: ");
    int i;
    for (i = 0; i < 3; i++) {
      printf("%c, ", puzzle[i]);
    }
    printf("%c.\n", puzzle[3]);
    printf("Enter your solution: ");
    //takes in input and gets rid of newlines and whitespaces
    scanf(" %[^\n]s", answer);
    if (answer[0] == '\n') {
      fgets(answer, 81, stdin);
    }
    if (answer[strlen(answer) - 1] == '\n') {
      answer[strlen(answer) - 1] = '\0';
    }

    i = 0;
    int j = 0;
    //puts user expression into new string only that doesnt have spaces
    while (answer[i] != '\0') {
      if (answer[i] == ' ') {
        i++;
      } else {
        only[j] = answer[i];
        j++;
        i++;
      }
    }
    only[j] = '\0';
    i = 0;
    j = 0;
    //pushes all characters from only into fakestack that are numbers to perform validity check
    while (only[j] != '\0') {
      if (isdigit(only[j])) {
        push(fakestack, only[j]);
        j++;
      } else {
        j++;
      }
    }
    //next 2 big if statements check validity of user inputs
    if (checkvalidity(answer) == 0) {
      printf("Error! invalid symbol entered. Please try again.\n\n");
      emptythestack(fakestack);
      char *saver;
      if (option == 'E') {
        saver = easyrandom();
      } else if (option == 'M') {
        saver = mediumrandom();
      } else if (option == 'H') {
        saver = hardrandom();
      } else {
        saver = easyrandom();
      }
      free(puzzle);
      puzzle = saver;
      valid = 0;
      continue;  //continues loop until valid input is read
    }

    if (allnumbersexist(puzzle, fakestack) == 0) {
      printf(
          "Error! You must use all four numbers, and use each one only once. "
          "Please try again.\n\n");
      emptythestack(fakestack);
      char *saver;
      if (option == 'E') {
        saver = easyrandom();
      } else if (option == 'M') {
        saver = mediumrandom();
      } else if (option == 'H') {
        saver = hardrandom();
      } else {
        saver = easyrandom();
      }
      free(puzzle);
      puzzle = saver;
      valid = 0;
      continue;  //continues loop until valid input is read
    } else {

      valid = 1;
      break;
    }
  }

    int i = 0;
    //variables used for logic in while loop
    int x;  
    int y;
    char oper;
    int num;
    int stacknumber = 0; //counter for front parentheses used in this function
    int counterpart = 0; //counter for closed parantheses used in this function

    i = 0;
    int openings = 0;  //counter for front parentheses in closings()
    int closings = 0;  //counter for closing parentheses in closings()
    while (only[i] != '\0') {
    if (only[i] == '(') {
      openings++;
      i++;
      continue;
    } else if (only[i] == ')') {
      closings++;
      i++;
      continue;
    }
    else{
      i++;
      continue;
    }
  }
  //if there are more closing parantheses than openings, it frees all stacks and sends them into closings() for different calculations
  if (openings != closings) {
    closing(only, charstack, intstack, parcharstack, parintstack);
    intemptythestack(intstack);
    emptythestack(charstack);
    intemptythestack(parintstack);
    emptythestack(parcharstack);
    emptythestack(fakestack);
    free(puzzle);
    free(fakestack);
    free(intstack);
    free(charstack);
    free(parintstack);
    free(parcharstack);
    return;
  }
  i = 0;

//this while loop is the bulk of all the logic in evauluating expressoins
  while (only[i] != '\0') {
    if (only[i] == '(') {
      stacknumber++;
      i++;
      while (stacknumber != counterpart) { //only breaks once number of opening and closing parentheses
        if (only[i] == '(') {
          stacknumber++;
          i++;
          continue;
        } else if (only[i] == ')') {
          counterpart++;
          if (counterpart == stacknumber) { 
            break;
          }
          if (intstacksize(parintstack) == 1) {  //no calculations in parentheses need to take place, so we push inner parentheses value into main integer stack
            if (only[i + 1] == '\0') {
              intpush(intstack, parintstack->top->data);
              intemptythestack(parintstack);
              break;
            } else {
              i++;
              break;
            }
          } else {
            parintstack = intreversestack(parintstack);  //reverses parentheses stacks
            parcharstack = reversestack(parcharstack);
            doublestacks(intstack, parintstack, parcharstack, 0); //performs parentheses stacks operations
            i++;
            continue;
          }
        }
        if (isdigit(only[i])) { //pushes numbers onto parentheses integer stack
          intpush(parintstack, (only[i] - '0'));
          i++;
          continue;
        } else {
          if (only[i] == '*' || only[i] == '/') {  //if a * or / is read, then calculations are performed right away
            push(parcharstack, only[i]);
            if (only[i + 1] == '(') {  //indicates another parentheses in front of operation, so loop needs to continue
              oper = pop(charstack);
              push(charstack, oper);
              intpush(intstack, parintstack->top->data);
              intemptythestack(parintstack);
              i++;
              continue;
            }
            oper = pop(parcharstack);
            intpush(parintstack, (only[i + 1]) - '0'); // if there is no opening parenthes in front, it must be a number
            i++;
            x = intpop(parintstack);
            y = intpop(parintstack);
            num = expressions(y, x, oper);
            printf("%d%c%d = %d.\n", y, oper, x, num);  //although parts of this code are available in other parts of the program, each one has small tweaks serving a different purpose. It is not a lack of functional decomposition
            intpush(parintstack, num);
            i++;
          } else {
            push(parcharstack, only[i]);
            i++;
          }
        }
      }
      if (intstacksize(parintstack) == 1) {  //if only one value is in parentheses after calculations it must be pushed into the integer stack
        intpush(intstack, parintstack->top->data);
        emptythestack(parcharstack);
        intemptythestack(parintstack);
        continue;
      } else {
        parintstack = intreversestack(parintstack); //otherwise, stacks need to be reversed
        parcharstack = reversestack(parcharstack);
        doublestacks(intstack, parintstack, parcharstack, 1); //1 indicates num must be pushed into integer stack
        emptythestack(parcharstack);
        intemptythestack(parintstack);
        if (only[i + 1] == '\0') {
          break;
        }
        if (only[i] == '\0') {
          break;
        }
        continue;
      }

    } else if (only[i] == ')') { //increments closing parentheses and continues loop
      counterpart++;
      i++;
    continue;
    } else if (only[i] == '\n' || only[i] == ' ' || only[i] == '0') { //indicates loop needs to be continued
      i++;
      continue;
    } else { 
      if (exists(charstack, '*') == 1 || exists(charstack, '/') == 1) { //case happens when there is an opening parentheses after a * or /, so calculations must happen right away
        charstack = reversestack(charstack);
        intstack = intreversestack(intstack);
        twostacks(intstack, charstack);
      }
      //Same as parentheses statement up top but does not need to account for number of closed and opened parentheses
      if (isdigit(only[i])) {
        intpush(intstack, only[i] - '0');
        i++;
      } else {
        if (only[i] == '*' || only[i] == '/') {
          push(charstack, only[i]);
          if (only[i + 1] == '(') { //cannot continue since the opening parentheses cannot be pushed into the integer stack
            i++;
            continue;
          }
          oper = pop(charstack);
          intpush(intstack, (only[i + 1]) - '0');
          i++;
          x = intpop(intstack);
          y = intpop(intstack);
          num = expressions(y, x, oper);
          printf("%d%c%d = %d.\n", y, oper, x, num);
          intpush(intstack, num);
          i++;
        } else {
          push(charstack, only[i]);
          i++;
        }
      }
    }
  }

  //if theymatch is equal to 0, then there are too many values in the expresssion
  if (theymatch(charstack, intstack) == 0) {
    //even if there are too many values, some expressions must still take place
    while(emptystack(charstack) == 0){
      oper = pop(charstack);
      int y = intpop(intstack);
      int x = intpop(intstack);
      num = expressions(x,y,oper);
      printf("%d%c%d = %d.\n", x, oper, y, num);
      intpush(intstack, num);           
    }
    printf("Error! Too many values in the expression.\n");
    //this following block of code occurs many times to free all stacks and the puzzle array
    intemptythestack(intstack);  
    emptythestack(charstack);
    intemptythestack(parintstack);
    emptythestack(parcharstack);
    emptythestack(fakestack);
    free(puzzle);
    free(fakestack);
    free(intstack);
    free(charstack);
    free(parintstack);
    free(parcharstack);
    return;
    //occurs when no calculations need to take place
  } else if (stacksize(charstack) == 0) {
    if (intstack->top->data == 24) {
      printf("Well done! You are a math genius.\n\n");
    } else {
      printf("Sorry. Your solution did not evaluate to 24.\n\n");
    }
    intemptythestack(intstack);
    emptythestack(charstack);
    intemptythestack(parintstack);
    emptythestack(parcharstack);
    emptythestack(fakestack);
    free(puzzle);
    free(fakestack);
    free(intstack);
    free(charstack);
    free(parintstack);
    free(parcharstack);
    return;
  }

  //this block executes once a succesful expression is evaluated
  else {
    charstack = reversestack(charstack);
    intstack = intreversestack(intstack);
    twostacks(intstack, charstack);

    if (intstack->top->data == 24) {
      printf("Well done! You are a math genius.\n\n");
    } else {
      printf("Sorry. Your solution did not evaluate to 24.\n\n");
    }
    intemptythestack(intstack);
    emptythestack(charstack);
    intemptythestack(parintstack);
    emptythestack(parcharstack);
    emptythestack(fakestack);
    free(puzzle);
    free(fakestack);
    free(intstack);
    free(charstack);
    free(parintstack);
    free(parcharstack);
    return;
  }

}

//passes or switches the program with correct option character and puzzle into playgame()
void switcher(char option) {
  char *puzzle;
  if (option == 'E') {
    puzzle = easyrandom();
  } else if (option == 'M') {
    puzzle = mediumrandom();
  } else if (option == 'H') {
    puzzle = hardrandom();
  } else {
    puzzle = easyrandom();
  }

  playgame(puzzle, option);
}

//called in beggining and if option 2 is selected
char intermediate() {
  printf("Choose your difficulty level: E for easy, M for medium, and H for "
         "hard (default is easy).\n");
  printf("Your choice --> ");
  char option;
  scanf(" %c", &option);
  switcher(option);
  return option;
}

//calls intermediate once to play singular game and then enters while loop for further menu options
int main() {
  srand(1);
  beggining();
  char option = intermediate();
  int decide = 0;
  while (decide != 3) {
    decide = menu();
    if (decide == 1) {
      switcher(option);
    } else if (decide == 2) {
      option = intermediate();
    } else if (decide == 3) {
      break;
    }
  }
  printf("\nThanks for playing!\n");
  printf("Exiting...");

  return 0;
}