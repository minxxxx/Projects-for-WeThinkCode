from django import forms
from django.contrib.auth.models import User

class InscriptionForm(forms.Form):
	username = forms.CharField(required = True)
	password = forms.CharField(required = True, widget=forms.PasswordInput, initial='')
	verif_password = forms.CharField(required = True, widget=forms.PasswordInput, initial='')
	def clean(self):
		form_data = super(InscriptionForm, self).clean() # appliquer la validation de la classe mere
		u = User.objects.filter(username = form_data['username']) # recherche d'unicite
		if len(u) > 0:
			self._errors['username'] = ["Le nom saisi est déjà pris"]
		if form_data['password'] != form_data['verif_password']:
			self._errors['password'] = ["Le mot de passe doit être identique dans les 2 champs password"]
		return form_data