# coding : utf8

from django.shortcuts import render, HttpResponse

# Create your views here.
def ex01_django(request):
	return render(request, 'ex01/django.html')


def ex01_affichage(request):
	return render(request, 'ex01/affichage.html')

def ex01_templates(request):
	return render(request, 'ex01/templates.html')

