from django.conf.urls import url

from . import views

urlpatterns = [
	url(r'^populate/', views.populate),
	url(r'^display/', views.display),
	url(r'^remove/', views.remove),

]