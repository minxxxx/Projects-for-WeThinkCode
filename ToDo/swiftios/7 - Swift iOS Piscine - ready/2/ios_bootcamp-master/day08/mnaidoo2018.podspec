#
# Be sure to run `pod lib lint mnaidoo2018.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'mnaidoo2018'
  s.version          = '0.1.0'
  s.summary          = 'A CoreData Framework'
  s.swift_version    = '4.1.2'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = 'We will be creating a package that will use the CoreData framework to learn how to use data persistence and models.'

  s.homepage         = 'https://github.com/miinnie19/mnaidoo2018'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'miinnie19' => 'mnaidoo@student.wethinkcode.co.za' }
  s.source           = { :git => 'https://github.com/miinnie19/mnaidoo2018.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

  s.source_files = 'mnaidoo2018/Classes/**/*'
  
   s.resource_bundles = {
     'mnaidoo2018' => ['mnaidoo2018/article.xcdatamodeld']
   }
  # s.public_header_files = 'Pod/Classes/**/*.h'
   s.frameworks = 'UIKit', 'MapKit', 'CoreData'
  # s.dependency 'AFNetworking', '~> 2.3'
end
