from django.contrib.auth.models import AbstractUser, User
from django.db import models

from django.db.models.signals import post_save
from django.dispatch import receiver

from django.contrib.auth.models import User


# Create your models here.
class Post(models.Model):
    title = models.CharField(max_length=64, null=False, unique=True)
    author = models.ForeignKey(User, null=False, )
    created = models.DateTimeField(auto_now_add=True)
    content = models.TextField(null=False)

    def __str__(self):
        return (self.title)


class Comment(models.Model):
    author = models.ForeignKey(User, null=False, )
    postid = models.ForeignKey(Post, null=True)
    commentid = models.ForeignKey('self', null=True)
    created = models.DateTimeField(auto_now_add=True)
    content = models.TextField(null=False)

    def getid(self):
        return (self.id)


class Profile(models.Model):
    user = models.OneToOneField(User, on_delete=models.CASCADE)
    description = models.TextField(max_length=500, blank=True, default='')
    avatar = models.ImageField(upload_to='avatar', null=True, default='')

    @property
    def avatar_url(self):
        if self.avatar and hasattr(self.avatar, 'url'):
            return self.avatar.url


@receiver(post_save, sender=User)
def create_user_profile(sender, instance, created, **kwargs):
    if created:
        Profile.objects.create(user=instance)


@receiver(post_save, sender=User)
def save_user_profile(sender, instance, **kwargs):
    instance.profile.save()
