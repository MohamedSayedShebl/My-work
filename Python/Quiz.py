from question import Questions

question_prompts=[
    "which player has the most red cards?,\n(a)gattuso\n(b)ramos\n(c)pepe\n(d)roy keane\n",
    "who won the ballon do'r 2006?,\n(a)zidane\n(b)cannavaro\n(c)michael owen\n(d)ronaldinho\n",
    "which national team won the 2006 world cup?,\n(a)italy\n(b)france\n(c)brazil\n(d)germany\n"
]

test_questions=[Questions(question_prompts[0],"b")
    ,Questions(question_prompts[1],"b")
    ,Questions(question_prompts[2],"a")
]

def run_test(test_questions):
    score = 0
    for question in test_questions:
        answer=input(question.prompt)
        if answer not in ("abcd"):
            print("enta 8aby s7")
        if answer==question.answer:
            score+=1
    print("You scored " + str(score) + "out of "+str(len(test_questions)))
    if score<2:
        print("ya teez")
    else:
        print("bravo")




run_test(test_questions)

other_questions=[
    "Who scored the fastest goal in the premier league?,\n(a)Shane Long\n(b)Sergio Aguero]\n(c)Dider Drogba\n(d)Callum Wilson\n",
    "What year did Borussia Dortmund win the Champions League?,\n(a)1998\n(b)1997\n(c)2000\n(d)1995\n",
    "Who is Manchester United's top goal scorer in the FA cup?,\n(a)Cristiano Ronaldo\n(b)Bobby Charlton\n(c)Wayne Rooney\n(d)Ruud Van Nistelroy\n",
    "Which team won the first Europa League?,\n(a)Atletico Madrid\n(b)Sevilla\n(c)Frankfurt\n(d)Marseille\n"
]

OTHER__QUESTIONS=[
    Questions(other_questions[0],"a"),
    Questions(other_questions[1],"b"),
    Questions(other_questions[2],"c"),
    Questions(other_questions[3],"a")
]
print("Now onto the other quiz")
run_test(OTHER__QUESTIONS)