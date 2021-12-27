from django.shortcuts import render

# Create your views here.
from django.views.generic.edit import CreateView
from django.contrib.auth.models import User
from .forms import InscriptionForm

class RegisterView(CreateView):
    model = User
    form_class = InscriptionForm
# comment faire pour utiliser un formulaire autre que celui par defaut afin d'ajouter un @d champ password??