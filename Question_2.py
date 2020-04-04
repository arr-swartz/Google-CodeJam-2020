# Nesting Depth

t = int(input())     #number of testcase

for j in range(t):
    s = input()      #input string
    new_s =""         #output string
    remain_brac = 0    #remaining unmatched brackets
    
    for i in range(0,len(s)):
        if i == 0:                       #adding opening brackets at beginning
            new_s+=("("*int(s[i])+s[i])  
            remain_brac+=int(s[i])
        else:
            if int(s[i]) == int(s[i-1]):     #adding repeated value
                new_s+=s[i]
            elif int(s[i]) < int(s[i-1]):              #adding closing brackets for reducing depth
                remain_brac -= (int(s[i-1])-int(s[i]))
                new_s+=(")"*(int(s[i-1])-int(s[i]))+s[i])
            else:                                            #adding more opening brackets increasing depth
                remain_brac += (int(s[i])-int(s[i-1]))
                new_s+=("("*(int(s[i])-int(s[i-1]))+s[i])
                
    new_s+=(")"*remain_brac)   #adding remaing closing brackets
    
    print("Case #"+str(j+1)+": "+new_s)
