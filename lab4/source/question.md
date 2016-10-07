###Question
- If we had to account for whitespace in this assignment, we would have to
  modify the lexer. Where we ignore whitespace currently with `[ \t\n\r]`, we
  would need to watch for those characters, and specifically after certain
  declarations confirm that the following lines contain a single tab, etc.
  This would greatly complicate many of the rules governing control flow
  statements in our lexer. 
