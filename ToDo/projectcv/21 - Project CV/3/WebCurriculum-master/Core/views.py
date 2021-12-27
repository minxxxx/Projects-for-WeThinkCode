from django.shortcuts import render

from Fortytwo.views import get_course
from Contact.views import contact
from Portfolio.views import portfolio
from Presentation.views import presentation


def index(request):
    profiles = presentation
    projects = portfolio
    skill = get_course(request)
    form = contact(request)
    return render(request, 'Core/index.html', {
        'profiles': profiles,
        'projects': projects,
        'form': form,
        'skill': skill
    })