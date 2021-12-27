from django.conf.urls import url

from . import views

urlpatterns = [
    url(r'^django/', views.ex01_django),
    url(r'^affichage/', views.ex01_affichage),
    url(r'^templates/', views.ex01_templates),

]