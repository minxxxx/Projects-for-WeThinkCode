from django.shortcuts import render
from gigaapp.forms import ContactForm

# Create your views here.
def some_page(request):
	f = ContactForm({'subject': 'Hello',
	                     'email': 'adrian@example.com',
	                     'message': 'Nice site!'})
	return HttpResponse(f.as_p())