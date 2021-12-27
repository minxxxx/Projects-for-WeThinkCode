import requests


def get_course(request):
    if 'course' not in request.session:
        r = requests.get('https://api.intrav2.42.fr/users/bmartins?token=4489e7e5a53ae6c1f468a773a58fbd706216967a')
        json = r.json()
        course = {}
        course['level'] = json['cursus'][0]['level']
        course['grade'] = json['cursus'][0]['grade']
        course['skills'] = json['cursus'][0]['skills']
        course['projects'] = json['cursus'][0]['projects']
        print(course['level'])
        print(course['grade'])
        print(course['skills'])
        print(course['projects'])
        request.session['course'] = course
    return request.session['course']