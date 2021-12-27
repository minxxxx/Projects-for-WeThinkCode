from Contact.form import ContactForm
#from django.core.mail import send_mail


def contact(request):
    form = ContactForm(request.POST)
    if request.method == 'POST':
        if form.is_valid():
            form.name = form.cleaned_data['name']
            form.message = form.cleaned_data['message']
            form.sender = form.cleaned_data['sender']
            form.copy = form.cleaned_data['copy']
            recipients = ['elhensar@gmail.com']
            if form.copy:
                recipients.append(form.sender)
                #send_mail(form.name, form.message, form.sender, recipients)
            form.valid = True
    else:
        form = ContactForm()
    return form