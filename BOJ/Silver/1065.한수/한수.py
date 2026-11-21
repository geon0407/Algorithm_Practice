#arthmetic.py
a = int(input())
ans = 0

if a < 100 :
  print(a)
else :
  while a > 100 :
    #print(str(a) + " : ")
    n1 = int(a / 100)
    n2 = int((a / 10) % 10)
    n3 = int(a % 10)
    if(n1 - n2 == n2 - n3) :
      #print("Okay!\n")
      ans += 1
    a -= 1  

  print(ans+99)      
            