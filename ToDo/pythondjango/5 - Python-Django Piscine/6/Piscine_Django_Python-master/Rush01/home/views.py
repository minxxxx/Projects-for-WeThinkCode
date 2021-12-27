from django.views.generic import ListView, View
from django.contrib.auth.views import logout
from home.models import Post, Comment
from collections import OrderedDict

from django import forms
from django.contrib.auth import logout
from django.contrib.auth.decorators import user_passes_test
from django.contrib.auth.forms import AuthenticationForm, UserCreationForm
from django.contrib.auth.models import User
from django.shortcuts import redirect, render
from django.urls import reverse_lazy
from django.views.generic import RedirectView, FormView, CreateView

from home.models import Profile


class Home(RedirectView):
    url = reverse_lazy('ListePost')


class Login(FormView):
    login_url = 'home/Login.html'
    form_class = AuthenticationForm
    success_url = "/"


class Registration(CreateView):
    form_class = UserCreationForm
    success_url = reverse_lazy('Login')

    def form_valid(self, form):
        form.save()
        return super().form_valid(form)


class Logout(RedirectView):
    """
    Provides users the ability to logout
    """
    url = reverse_lazy('Home')
    success_url = reverse_lazy('Home')

    def get(self, request, *args, **kwargs):
        logout(request)
        # print('logout')
        return super(Logout, self).get(request, *args, **kwargs)


class ListePost(ListView):
    model = Post
    ordering = ['-created']
    paginate_by = 10


class Detail(View):
    model = Comment
    template_name = 'home/detail.html'

    # returns an OrderedDict of { comment_id: [child_ids,]}
    def create_liste_comments(postid):
        dic = OrderedDict()
        comments = Comment.objects.filter(postid_id=postid).order_by('-created')
        print(len(comments))
        for comment in comments:
            c = comment.commentid_id
            if c is None:
                c = 0
            dic.setdefault(c, [])
            dic[c].append(comment)
        return dic

    def level_dict(d, first=0, lst=[], level=0):
        if first in d:
            for elem in d[first]:
                lst.append([elem, level])
                print(elem.pk)
                Detail.level_dict(d, elem.pk, lst, level + 1)

    def get(self, request, *args, **kwargs):

        if 'pk' in kwargs:
            postid = kwargs['pk']
            d = Detail.create_liste_comments(postid)
            comments = []
            Detail.level_dict(d=d, first=0, lst=comments)
            post = Post.objects.get(pk=postid)
            context = {}
            context['comments'] = comments
            context['pk'] = postid
            context['post'] = post
            kwargs = None
            return render(request, self.template_name, context)


class NewPost(CreateView):
    model = Post
    fields = ['title', 'content', ]
    success_url = reverse_lazy('ListePost')

    def form_valid(self, form):
        post = form.save(commit=False)
        user = self.request.user
        post.author = user
        return super(NewPost, self).form_valid(form)


class NewCommentPost(CreateView):
    model = Comment
    fields = ['content', ]
    success_url = reverse_lazy('ListePost')

    def form_valid(self, form, *args, **kwargs):

        postid = self.kwargs['slug']
        comment = form.save(commit=False)
        comment.postid_id = postid
        user = self.request.user
        comment.author = user
        return super(NewCommentPost, self).form_valid(form)

    def get_success_url(self, **kwargs):
        if kwargs != None:
            return reverse_lazy('DetailPost', kwargs={'pk': self.kwargs['slug']})
        else:
            return reverse_lazy('ListePost')


class NewCommentComment(CreateView):
    model = Comment
    fields = ['content', ]
    success_url = reverse_lazy('ListePost')

    def form_valid(self, form, *args, **kwargs):

        commentid = self.kwargs['slug']
        comment = form.save(commit=False)
        comment.commentid_id = commentid
        commentpere = Comment.objects.filter(id=commentid)
        comment.postid_id = commentpere[0].postid_id
        user = self.request.user
        comment.author = user
        return super(NewCommentComment, self).form_valid(form)

    def get_success_url(self, **kwargs):
        if kwargs != None:
            commentid = self.kwargs['slug']
            commentpere = Comment.objects.filter(id=commentid)
            return reverse_lazy('DetailPost', kwargs={'pk': commentpere[0].postid_id})
        else:
            return reverse_lazy('ListePost')


class UserForm(forms.ModelForm):
    class Meta:
        model = User
        fields = ('first_name', 'last_name', 'email')


class UserAdminForm(forms.ModelForm):
    class Meta:
        model = User
        fields = ('first_name', 'last_name', 'email', 'is_superuser')


class ProfileForm(forms.ModelForm):
    class Meta:
        model = Profile
        fields = ('description', 'avatar')


def update_profile(request):
    if request.method == 'POST':
        user_form = UserForm(request.POST, instance=request.user)
        profile_form = ProfileForm(request.POST, request.FILES, instance=request.user.profile)
        if user_form.is_valid() and profile_form.is_valid():
            user_form.save()
            profile_form.save()
            return redirect('/')
    else:
        user_form = UserForm(instance=request.user)
        profile_form = ProfileForm(instance=request.user.profile)
    return render(request, 'home/profile.html', {
        'user_form': user_form,
        'profile_form': profile_form
    })


@user_passes_test(lambda u: u.is_superuser)
def update_profile_other(request, username):
    if request.method == 'POST':
        user_form = UserAdminForm(request.POST, instance=User.objects.get(username=username))
        profile_form = ProfileForm(request.POST, request.FILES,
                                   instance=Profile.objects.get(user=User.objects.get(username=username)))
        if user_form.is_valid() and profile_form.is_valid():
            user_form.save()
            profile_form.save()
            return redirect('/')
    else:
        user_form = UserAdminForm(instance=User.objects.get(username=username))
        profile_form = ProfileForm(instance=Profile.objects.get(user=User.objects.get(username=username)))
    return render(request, 'home/profile.html', {
        'user_form': user_form,
        'profile_form': profile_form,
        'impersonate': username
    })
