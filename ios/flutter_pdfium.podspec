version = '7442'

Pod::Spec.new do |s|
  s.name             = 'flutter_pdfium'
  s.version          = '0.0.1'
  s.summary          = 'A new Flutter FFI plugin project.'
  s.description      = <<-DESC
A new Flutter FFI plugin project.
                       DESC
  s.homepage         = 'http://example.com'
  s.license          = { :file => '../LICENSE' }
  s.author           = { 'Your Company' => 'email@example.com' }

  # This will ensure the source files in Classes/ are included in the native
  # builds of apps using this FFI plugin. Podspec does not support relative
  # paths, so Classes contains a forwarder C file that relatively imports
  # `../src/*` so that the C sources can be shared among all target platforms.
  s.source           = { :path => '.' }
  s.source_files = 'Classes/**/*'
  s.dependency 'Flutter'
  s.platform = :ios, '12.0'

  # Flutter.framework does not contain a i386 slice.
  s.pod_target_xcconfig = { 'DEFINES_MODULE' => 'YES', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386' }
  s.swift_version = '5.0'

  s.prepare_command = <<-CMD
    mkdir -p .tmp
    cd .tmp
    curl -Lo pdfium.tgz https://github.com/paulocoutinhox/pdfium-lib/releases/download/#{version}/ios.tgz
    tar -xzf pdfium.tgz
    rm pdfium.tgz
    cd ..
    mkdir -p Frameworks
    mv .tmp/release/pdfium.xcframework Frameworks/
    rm -rf .tmp/
  CMD

  s.libraries = ['c++', 'z']
  s.vendored_frameworks = 'Frameworks/pdfium.xcframework'
end
