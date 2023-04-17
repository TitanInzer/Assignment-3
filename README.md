# Assignment-3

# Question 1:

  In Question 1 the goal is to convert an infix notation expression into a postfix notation expression.
  
  The way this code operates is it first checks if the given expression is balanced.
  
  If balanced it will then convert the expression from Infix to Postfix.
  
  This is done by using the C++ Implementation of Stack, and then when in stack taking elements from the stack based on the precedence of the expressions.
  
  Test Case 1:
    A+BxC-(D/E)%F
    
   <img width="275" alt="2023-04-17 (2)" src="https://user-images.githubusercontent.com/124959427/232593183-9c66dd85-d467-4405-a45a-88b2b226c088.png">
   
   Since this is a Balanced Expression it is returned in Postfix.

   Test Case 2:
   ((A+B)x-D/E
   
   <img width="224" alt="2023-04-17 (3)" src="https://user-images.githubusercontent.com/124959427/232593324-37129008-6c0f-4916-9b7e-bfafe321e76c.png">
    
   This Expression is not Balanced so the Exception is thrown.
   
# Question 2:

  Question 2 asks us to make and implement a Queue which can Push, Pop, Check the First Element, Check if it is empty, how big the Queue is.
  
  The given code can do that. 
  
  First We push 3 elements into the Queue.
  
  Then we check the front element.
  
  Next we pop that element out of the Queue.
  
  Then make sure that only 2 elements remain.
  
  Finally we check if it is empty or not.
  
  <img width="130" alt="2023-04-17 (5)" src="https://user-images.githubusercontent.com/124959427/232596667-fa9e1c2d-b105-45ab-94eb-be35caabada2.png">
