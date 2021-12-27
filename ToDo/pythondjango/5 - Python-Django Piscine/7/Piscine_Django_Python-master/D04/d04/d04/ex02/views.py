from django.shortcuts import render, HttpResponse
from ex02.forms import MyForm
import datetime
import os.path
from django.conf import settings

# Create your views here.

# attention : il ne faut utiliser les variables globales qu'em lecture
# dans les fonctions.
# Car si on modifie une variable globale dans une fonction
# python va en faire un  copie locale !
hist_filename = getattr(settings, "HISTORY_FILE", None)
if not hist_filename:
	hist_filename = 'default.log'

def lire_historique():
	histo = []
	if os.path.isfile(hist_filename) : # on ne lit que si le fichier existe
		with open(hist_filename) as f:
			histo = f.readlines()
	return histo

def ajouter_a_historique(msg):
	f = open(hist_filename,'a') # ecrire en ajout
	f.write(msg+'\n') # ecrire le message dans le fichier
	f.close()


def ex02(request):
	msgs = lire_historique()
	if request.method == 'POST':
		form = MyForm (request.POST)
		if form.is_valid():
			date = datetime.datetime.now()
			msg = form.cleaned_data['message']
			msg += ' ' + str(date)
			ajouter_a_historique(msg)
			msgs.append(msg) # ajoute le message a la liste en memoire

	else: # methode 'GET':
		form = MyForm ()

	return render ( request , 'ex02/form.html', {'form': form, 'msgs': msgs})
