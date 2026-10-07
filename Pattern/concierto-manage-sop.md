
# Concierto Manage | Standard Operating Procedure (SOP)

## Document Overview
This Standard Operating Procedure (SOP) defines the end-to-end process for deploying a new service to the Kubernetes cluster (EKS) and onboarding the source code repository to the automated backup routine.

------------------------------
### Pre-Requisites & Required Pre-Deployment Information
Before initiating any changes in the configuration files, you must coordinate with the **Development Team** to gather essential architecture parameters.

* **Service Listening Port**: The container network port (e.g., 8080) where the app accepts traffic. Required to map traffic from the Kubernetes Service down to your container.
* **Health Check Path**: The application status endpoint (e.g., /healthz). Used by Kubernetes probes to monitor runtime health and automatically restart failed Pods.
* **Context Path**: The base URI prefix for endpoints (e.g., /api/v1/payments/). Critical for the Ingress Controller to accurately route traffic to the correct microservice.

------------------------------
### Pipeline Parameters Specifications
When modifying pipeline template configurations, ensure the following parameters are accurately populated in your deployment files.

```bash
parameters:
  - name: p_stagename
    type: string  # Purpose: Defines the execution environment tier (e.g., 'dev', 'uat', 'demo').
  - name: p_checkout
    type: boolean # Purpose: Controls whether the pipeline pulls application source code or baseline infrastructure assets.
  - name: p_troubleshooting
    type: boolean # Purpose: Toggles verbose logging, debug modes, and trace steps if errors occur during build execution.
  - name: p_ecr
    type: string  # Purpose: Holds the destination target URL for the AWS Elastic Container Registry (ECR).
  - name: p_dockerfile
    type: string  # Purpose: Specifies the relative file path to the Dockerfile inside the source code repository.
  - name: p_image_name
    type: string  # Purpose: Establishes the precise naming convention for the resulting container artifact.
  - name: p_arguments
    type: string  # Purpose: Passes external variables, flags, or configuration arguments into the Docker build engine.
```

------------------------------
### Repository Model
The operations team utilizes a strict Separation of Concerns model split across two distinct repository types within Azure DevOps:

* **Application Repositories (Many)**: Each microservice has an isolated source code repository containing application business logic, application code, and the service-specific Dockerfile.
* **Central CI-CD Infrastructure Repository (Single)**: A centralized, shared repository used strictly by DevOps to store all Kubernetes manifests (.yaml), environment variables, configurations, and core pipeline workflow templates for the entire engineering ecosystem.

------------------------------
## Step-by-Step New Service Deployment Execution

**Note on Reusability**: Do not create manifest structures completely from scratch. Locate a pre-existing service setup within the central CI-CD repository, copy its files, and modify the specific naming strings, labels, and parameters to align with the new service requirements.

### Step 1: Create Deployment YAML

* Add the deployment configuration file into the **/k8s_deployment_yamls** folder inside the central CI-CD repository.

### Step 2: Create Service YAML

* Add the network service definition file into the **/k8s_service_yamls folder** inside the central CI-CD repository.

### Step 3: Create Ingress YAML (Conditional)

* If the application requires external reachability from outside the corporate network or VPC, add an Ingress file into the **/k8s_ingress_yamls folder**.

### Step 4: Create or Update ConfigMap

* Add or edit configuration manifests inside the **/k8s_config_maps folder**. Verify that the ConfigMap name exactly matches the reference inside the deployment manifest created in Step 1.

### Step 5: Create Pipeline YAML

* Add the customized continuous integration/deployment pipeline driver file into the **/pipeline_yamls** directory.

### Final Step: Run Pipelines Sequence
Execute the workflow files in the following exact chronological order:
  1. Trigger and successfully complete the Environment ConfigMap Pipeline.
  2. Trigger and successfully complete the Service Deployment Pipeline.

------------------------------
## Automated Repository Backup Procedure
This process is fully automated via an orchestration script located on the maintenance branch.
### Target Location
Azure DevOps Maintenance Folder: **maintenance/maintenance-backup-azure-repos.yaml**
## Action Steps

   1. Navigate to the repository file referenced in the path above on the maintenance branch.
   2. Locate the designated array block labeled **repo_name**.
   3. Append your newly created application repository name to the string array.
   4. Commit the change directly to the maintenance branch. The background cron system automatically registers the change and initializes backups during the next scheduled cycle.

------------------------------
## Troubleshooting and Support Verification

* Manifest Validation Failures: Ensure all indented formatting spaces conform strictly to YAML guidelines. Use validation tools if linting errors block pipeline execution.
* Pipeline Failures: Check the p_troubleshooting toggle inside your pipeline configuration block to display full environment outputs during debugging sessions.



