from django.shortcuts import render
from .forms import DogImageForm
from .models import File

# Create your views here.
def dogpage(request):
	files = File.objects.all()
	if request.method == 'POST' :
		form = DogImageForm(request.POST, request.FILES)
		if form.is_valid(): 
			form.save()
		else:
			print('formulaire invalide')
	else:
		form = DogImageForm()
	return render(request, "dogapp/dogimage.html" , {'form' : form,   'files' : files})