from django.conf.urls import url

from django.contrib.auth import views as auth_views

from home.views import update_profile, update_profile_other
from . import views
from django.contrib.auth.decorators import login_required

urlpatterns = [
    url(r'^$', views.Home.as_view(), name='Home'),
    url(r'^login/$', auth_views.LoginView.as_view(template_name='home/LogIn.html'), name='Login'),
    url(r'^post/$', views.ListePost.as_view(template_name='home/listepost.html'), name='ListePost'),
    url(r'^logout$', views.Logout.as_view(), name='Logout'),
    url(r'^register/?$', views.Registration.as_view(template_name='home/Registration.html'), name='Register'),
    url(r'^detailpost/(?P<pk>[0-9]+)/?$', views.Detail.as_view(template_name='home/detail.html'), name='DetailPost'),
    url(r'^newpost/?$', login_required(views.NewPost.as_view(template_name='home/newpost.html')), name='NewPost'),
    url(r'^newcommentpost/(?P<slug>[0-9]+)/?$',
        login_required(views.NewCommentPost.as_view(template_name='home/newcomment.html')), name='NewCommentPost'),
    url(r'^newcommentcomment/(?P<slug>[0-9]+)/?$',
        login_required(views.NewCommentComment.as_view(template_name='home/newcomment.html')),
        name='NewCommentComment'),
    url(r'^profile/$', update_profile),
    url(r'^profile/(?P<username>\w{0,50})/$', update_profile_other),
]
