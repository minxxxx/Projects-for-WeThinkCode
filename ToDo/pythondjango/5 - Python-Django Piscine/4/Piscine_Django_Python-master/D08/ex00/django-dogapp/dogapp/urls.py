from django.conf.urls import url

from .views import dogpage

urlpatterns = [
	url(r'^$', dogpage, name='dogpage'),
]