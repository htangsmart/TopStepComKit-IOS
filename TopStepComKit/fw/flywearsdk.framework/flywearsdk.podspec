Pod::Spec.new do |s|
  s.name         = 'flywearsdk'
  s.summary      = 'flywearsdk module, M1 and above support xcode framworks.'
  s.version      = '1.0.7'
  s.description      = <<-DESC
  Private M1 and above support xcode framworks..
  DESC
  s.homepage         = "https://github.com"
  s.license          = 'MIT'
  s.author           = {"rainway" => "864901228@qq.com"}
  s.source           = {:path => "./"}
  s.social_media_url = 'http://www.lessney.com'
  s.platform     = :ios, '12.0'
  s.ios.deployment_target = '12.0'
  #s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
  
  s.libraries        = 'c++', 'z', 'sqlite3', 'bz2.1.0'
  s.frameworks       = 'Foundation', 'UIKit', 'CoreBluetooth'

  s.requires_arc = true
  s.vendored_frameworks = 'Products/flywearsdk.framework', 'Rtt/persimwearSDK.framework'
  s.resource = 'fw_res/WearApi.bundle'

  s.dependency 'ReactiveObjC'

end
