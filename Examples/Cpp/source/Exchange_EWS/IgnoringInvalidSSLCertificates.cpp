#include "Examples.h"
#include <system/object.h>
#include <system/enum_helpers.h>
#include <security/cryptography/x509_certificates/x509_chain.h>
#include <security/cryptography/x509_certificates/x509_certificate.h>
#include <net/service_point_manager.h>
#include <net/secure_protocols/ssl_stream.h>
#include <net/secure_protocols/ssl_policy_errors.h>

static bool RemoteCertificateValidationHandler(System::SharedPtr<System::Object> sender, System::SharedPtr<System::Security::Cryptography::X509Certificates::X509Certificate> certificate, System::SharedPtr<System::Security::Cryptography::X509Certificates::X509Chain> chain, System::Net::Security::SslPolicyErrors sslPolicyErrors)
{
    return true;
    //Ignore the checks and go ahead
}


void IgnoringInvalidSSLCertificates()
{
    // Register callback method for SSL validation event
    System::Net::ServicePointManager::get_ServerCertificateValidationCallback().connect(RemoteCertificateValidationHandler);
}

