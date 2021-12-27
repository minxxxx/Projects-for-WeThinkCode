from django import forms

class MyForm(forms.Form):
	#titleChoice = forms.ChoiceField(initial = '', required = True)
	# je definis dynamiquement mon champ choice en lui passant une liste de choix dans titleChoices
	def __init__(self, titleChoices, *args, **kwargs):
		super(MyForm, self).__init__(*args, **kwargs)
		self.fields['titleChoice'] = forms.ChoiceField(choices=[(str(o), str(o)) for o in titleChoices])