from django import forms

class MyForm(forms.Form):
	message = forms.CharField(required = True)