while(1):
	print "Enter a two digit number"
	n=input()
	arr=[]
	while(n>0):
		rem=n%10
		arr.append(rem)
		n/=10
	arr=arr[::-1]
	ans=""
	for i in xrange(0,len(arr)):
		temp=arr[i]*arr[i]
		if(temp<10):
			temp=str(temp)
			temp="0"+temp
		else:
			temp=str(temp)
		ans+=temp
	ans=int(ans)
	temp=arr[0]*arr[1]*2
	temp=temp*10
	ans=ans+temp
	print "Squre of given number :",ans
	print "Do you want to continue(1)?"
	ch=input()
	if(ch!=1):
		break