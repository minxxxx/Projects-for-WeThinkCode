from django.shortcuts import render, HttpResponse

# Create your views here.

def ex00(request):
	#return HttpResponse('<h1>ex00</h1>')
	return render(request, 'ex00/index.html')